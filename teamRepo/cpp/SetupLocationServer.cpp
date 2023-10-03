/* temporary file */

#include "../hpp/headers.hpp"
#include "../hpp/Server.hpp"

void setLocation(std::map<int, Server *> &mp, ServerConfig &server1, MimeAndError &mime)
{
	server1.host = "127.0.0.1";
	server1.port = 9090;
	server1.serverNames = "serv";
	server1.limitBodySize = 500000000;

	std::vector<location> loc(2);

	loc[0].alias = "/nfs/homes/zlazrak/Desktop/ww/teamRepo/error/error_pages/";
	loc[0].index.push_back("ind.php");
	loc[0].index.push_back("index.html");
	loc[0].index.push_back("ind.gif");
	// loc[0].index.push_back("a.out");
	loc[0].index.push_back("mian.cpp");
	// loc[0].index.push_back("smile.png");
	loc[0].autoIndex = true;
	// loc[0].cgi.insert({".php", "php-cgi"});
	// loc[1].cgi.insert({".out", "a.out"});

	loc[0].allowedMethods.insert("GET");
	loc[0].allowedMethods.insert("POST");
	loc[0].allowedMethods.insert("DELETE");
	// loc[0].canUpload = 1;

	loc[1].alias = "/nfs/homes/zlazrak/Desktop/ww/teamRepo/upload";
	loc[1].allowedMethods.insert("POST");
	loc[1].allowedMethods.insert("GET");

	loc[1].canUpload = true;

	server1.allLocations["/"] = loc[0];
	server1.allLocations["/upload"] = loc[1];

	// u_int16_t a = 404;
	server1.errorPages[404] = "/nfs/homes/yoyahya/Desktop/lastrepo/teamRepo/error/error_pages/error404.txt";
}	

/*

/upload/
{
	alias "/nfs/homes/zlazrak/Desktop/ww/team/testFiles"
}

*/