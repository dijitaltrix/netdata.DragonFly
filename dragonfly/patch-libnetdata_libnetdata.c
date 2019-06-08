--- libnetdata/libnetdata.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:33:02.000000000 +0100
@@ -5,7 +5,7 @@
 #ifdef __APPLE__
 #define INHERIT_NONE 0
 #endif /* __APPLE__ */
-#if defined(__FreeBSD__) || defined(__APPLE__)
+if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 #    define O_NOATIME     0
 #    define MADV_DONTFORK INHERIT_NONE
 #endif /* __FreeBSD__ || __APPLE__*/
@@ -1179,7 +1179,7 @@
 
 static int is_virtual_filesystem(const char *path, char **reason) {
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__DragonFly__) || defined(__FreeBSD__)
     (void)path;
     (void)reason;
 #else
