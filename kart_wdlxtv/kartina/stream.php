<?php
/*********************** Information *************************\
| $HeadURL$
| 
| Author: Jo2003
|
| Begin: 8/10/2010 / 4:48p
| 
| Last edited by: $Author$
| 
| $Id$
\*************************************************************/

require_once(dirname(__FILE__) . "/_kartina_auth.php.inc");

$id  = isset($_GET['id']) ? $_GET['id'] : 7;

$url = $kartAPI->getStreamUrl($id);

header("Location: ".$url);

?>