/***************************************************************
 * atomFeed.cpp
 * @Author:      Jonathan Verner (jonathan.verner@matfyz.cz)
 * @License:     GPL v2.0 or later
 * @Created:     2009-03-27.
 * @Last Change: 2009-03-27.
 * @Revision:    0.0
 * Description:
 * Usage:
 * TODO:
 *CHANGES:
 ***************************************************************/
 
#include "atomFeed.h"
#include "atomEntry.h"

#ifndef TIXML_USE_TICPP
#define TIXML_USE_TICPP
#endif
#include "ticpp/ticpp.h"


using namespace std;

atomFeed::atomFeed( gAPI *API ): api(API), xml(NULL) {}

bool atomFeed::addNewEntry( atomEntry *entry ) { 
  return entry->loadFromXML( api->POST( selfURL, entry->getStringXML() ) );
};

std::list<atomEntry *> atomFeed::getEntries() { 
  ticpp::Iterator< ticpp::Element > entry("entry");
  list<string> ret;
  for( entry = entry.begin( xml->FirstChildElement() ); entry != entry.end(); entry++ ) { 
   ret.push_back( new atomEntry( api, *entry ) );
  }
  return ret;
}



  

