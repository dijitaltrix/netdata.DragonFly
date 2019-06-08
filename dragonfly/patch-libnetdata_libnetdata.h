--- libnetdata/libnetdata.h	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 12:07:07.000000000 +0100
@@ -30,7 +30,7 @@
 
 #else /* !defined(ENABLE_JEMALLOC) && !defined(ENABLE_TCMALLOC) */
 
-#if !(defined(__FreeBSD__) || defined(__APPLE__))
+#if (!(defined(__FreeBSD__) || !(defined(__DragonFly__)) || defined(__APPLE__))
 #include <malloc.h>
 #endif /* __FreeBSD__ || __APPLE__ */
 
@@ -38,7 +38,7 @@
 
 // ----------------------------------------------------------------------------
 
-#if defined(__FreeBSD__)
+#if (defined(__FreeBSD__) || defined(__DragonFly__))
 #include <pthread_np.h>
 #define NETDATA_OS_TYPE "freebsd"
 #elif defined(__APPLE__)

@@ -80,7 +84,7 @@
 #include <sys/un.h>
 #include <time.h>
 #include <unistd.h>
-#include <uuid/uuid.h>
+//#include <uuid/uuid.h>

 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>