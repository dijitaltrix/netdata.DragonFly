--- libnetdata/log/log.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:36:11.000000000 +0100
@@ -31,7 +31,7 @@
 
 #define LOG_AUTH_KEY "auth"
 #define LOG_AUTHPRIV_KEY "authpriv"
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 # define LOG_CONSOLE_KEY "console"
 #endif
 #define LOG_CRON_KEY "cron"
@@ -50,7 +50,7 @@
 # define LOG_REMOTEAUTH_KEY "remoteauth"
 #endif
 #define LOG_NEWS_KEY "news"
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 # define LOG_NTP_KEY "ntp"
 #endif
 #define LOG_SECURITY_KEY "security"
@@ -74,7 +74,7 @@
 	static int 
 		hash_auth = 0,
 		hash_authpriv = 0,
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 		hash_console = 0,
 #endif
 		hash_cron = 0,
@@ -93,7 +93,7 @@
 		hash_remoteauth = 0,
 #endif
 		hash_news = 0,
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 		hash_ntp = 0,
 #endif
 		hash_security = 0,
@@ -116,7 +116,7 @@
 	{
 		hash_auth = simple_hash(LOG_AUTH_KEY);
 		hash_authpriv = simple_hash(LOG_AUTHPRIV_KEY);
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 		hash_console = simple_hash(LOG_CONSOLE_KEY);
 #endif
 		hash_cron = simple_hash(LOG_CRON_KEY);
@@ -135,7 +135,7 @@
 		hash_remoteauth = simple_hash(LOG_REMOTEAUTH_KEY);
 #endif
 		hash_news = simple_hash(LOG_NEWS_KEY);
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 		hash_ntp = simple_hash(LOG_NTP_KEY);
 #endif
 		hash_security = simple_hash(LOG_SECURITY_KEY);
@@ -164,7 +164,7 @@
 	{
 		return LOG_AUTHPRIV;
 	}
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 	else if ( hash == hash_console )
 	{
 		return LOG_CONSOLE;
@@ -225,7 +225,7 @@
 	{
 		return LOG_NEWS;
 	}
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 	else if ( hash == hash_ntp )
 	{
 		return LOG_NTP;
@@ -236,7 +236,7 @@
 		//FreeBSD is the unique that does not consider
 		//this facility deprecated. We are keeping
 		//it for other OS while they are kept in their headers.
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 		return LOG_SECURITY;
 #else
 		return LOG_AUTH;
@@ -312,7 +312,7 @@
 			{
 				return "authpriv";
 			}
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 		case LOG_CONSOLE:
 			{
 				return "console";
@@ -366,7 +366,7 @@
 			{
 				return "news";
 			}
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 		case LOG_NTP:
 			{
 				return "ntp" ;
