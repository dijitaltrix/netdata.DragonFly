--- libnetdata/libnetdata.h	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:45:29.000000000 +0100
@@ -38,7 +38,7 @@
 
 // ----------------------------------------------------------------------------
 
-#if defined(__FreeBSD__)
+if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <pthread_np.h>
 #define NETDATA_OS_TYPE "freebsd"
 #elif defined(__APPLE__)
