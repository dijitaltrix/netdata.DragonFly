--- libnetdata/libnetdata.h	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:45:29.000000000 +0100
@@ -30,24 +30,22 @@
 
 #else /* !defined(ENABLE_JEMALLOC) && !defined(ENABLE_TCMALLOC) */
 
-#if defined(__DragonFly__)
-#include <sys/malloc.h>
-#elif !(defined(__FreeBSD__) || defined(__APPLE__))
+#if !(defined(__FreeBSD__) || defined(__APPLE__))
 #include <malloc.h>
-#endif /* __APPLE__ || __FreeBSD__ */
+#endif /* __FreeBSD__ || __APPLE__ */
 
 #endif /* !defined(ENABLE_JEMALLOC) && !defined(ENABLE_TCMALLOC) */
 
 // ----------------------------------------------------------------------------
 
-#if (defined(__FreeBSD__) || defined(__DragonFly__))
+#if defined(__FreeBSD__)
 #include <pthread_np.h>
 #define NETDATA_OS_TYPE "freebsd"
 #elif defined(__APPLE__)
 #define NETDATA_OS_TYPE "macos"
 #else
 #define NETDATA_OS_TYPE "linux"
-#endif /* __APPLE__, __DragonFly__, __FreeBSD__*/
+#endif /* __FreeBSD__, __APPLE__*/
 
 #include <pthread.h>
 #include <errno.h>
