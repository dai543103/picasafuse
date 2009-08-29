#ifndef _gAPI_H
#define _gAPI_H

/***************************************************************
 * gAPI.h
 * @Author:      Jonathan Verner (jonathan.verner@matfyz.cz)
 * @License:     GPL v2.0 or later
 * @Created:     2009-02-26.
 * @Last Change: 2009-02-26.
 * @Revision:    0.0
 * Description:
 * Usage:
 * TODO:
 *CHANGES:
 ***************************************************************/

#include <string>
#include <set>
#include <list>


class gAPI { 
	private:
		std::string userName, authToken, appName;

	protected:
	  
		enum RESPONSE_CODES { OK = 200, 
				      CREATED = 201, 
				      NOT_MODIFIED = 304, 
				      BAD_REQUEST = 400,
				      UNAUTHORIZED = 401,
				      FORBIDDEN = 403,
				      NOT_FOUND = 404,
				      CONFLICT = 409,
				      INTERNAL_SEVER_ERROR = 500 };

		bool haveToken();
		void getAuthToken( const std::string &password );



		static void dropAuthKey( std::string &URL );
		static std::string extractAuthKey( std::string &URL );
		static std::string getAuthKey( const std::string &URL );
		static bool haveAuthKey( const std::string &URL );

		static int string2int(const std::string &number);
		static std::string extractVal( const std::string response, const std::string key );


		std::string DELETE( const std::string &feedURL );
		std::string PUT( const std::string &feedURL, const std::string &data );
		std::string POST( const std::string &feedURL, const std::string &data );
		std::string POST_FILE( const std::string &feedURL, const std::string &fileName, const std::string &contentType, std::list< std::string > &headers );

	public:
		enum exceptionType { GENERAL_ERROR };


	public:

		std::string GET( const std::string &feedURL );
		bool DOWNLOAD( const std::string &URL, const std::string &fileName );

		gAPI( const std::string &user = "", const std::string &password = "", const std::string app = "gAPI" );
		~gAPI();

		bool login( const std::string &password, const std::string &user = "");
		bool loggedIn() { return haveToken(); };
		std::string getUser() const;

		std::set<std::string> albumList( const std::string &user = "" ) throw ( enum exceptionType );

		friend class picasaAlbum;
		friend class picasaPhoto;
		friend class atomObj;
		friend class atomEntry;
		friend class atomFeed;
		friend class picasaObj;


};




#endif /* _gAPI_H */
