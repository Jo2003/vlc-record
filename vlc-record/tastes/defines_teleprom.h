/*********************** Information *************************\
| $HeadURL$
|
| Author: Jo2003
|
| Begin: 18.01.2010 / 09:19:48
|
| Last edited by: $Author$
|
| $Id$
\*************************************************************/
#ifndef __20140327__DEFINES_TELEPROM_H
   #define __20140327__DEFINES_TELEPROM_H

#include <QtGlobal>

#define APP_NAME      "Teleprom"
#define UPD_CHECK_URL "http://rt.coujo.de/teleprom_ver.xml"
#define BIN_NAME      "teleprom"
#define API_SERVER    "a01.teleprom.tv"
#define COMPANY_NAME  "Sat-Multimedia GmbH"
#define COMPANY_LINK  "<a href='http://sat-multimedia.de'>" COMPANY_NAME "</a>"
#define VERSION_APPENDIX

#define API_JSON_PATH  "/api/json2/"

// define classes of api client ...
#define ApiClient             CTelepromClient
// #define ApiParser             CNovoeParser

#endif // __20140327__DEFINES_TELEPROM_H
