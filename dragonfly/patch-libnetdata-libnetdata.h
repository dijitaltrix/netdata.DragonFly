diff --git a/libnetdata/libnetdata.h b/libnetdata/libnetdata.h
index 41642efd..1081aae8 100644
--- a/libnetdata/libnetdata.h
+++ b/libnetdata/libnetdata.h
@@ -30,15 +30,15 @@
 
 #else /* !defined(ENABLE_JEMALLOC) && !defined(ENABLE_TCMALLOC) */
 
-#if !(defined(__FreeBSD__) || defined(__APPLE__))
+#if !(defined(__FreeBSD__) || defined(__DragonFly__)) || defined(__APPLE__))
 #include <malloc.h>
-#endif /* __FreeBSD__ || __APPLE__ */
+#endif /* __FreeBSD__ || __DragonFly__ || __APPLE__ */
 
 #endif /* !defined(ENABLE_JEMALLOC) && !defined(ENABLE_TCMALLOC) */
 
 // ----------------------------------------------------------------------------
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__))
 #include <pthread_np.h>
 #define NETDATA_OS_TYPE "freebsd"
 #elif defined(__APPLE__)
@@ -80,7 +80,11 @@
 #include <sys/un.h>
 #include <time.h>
 #include <unistd.h>
+#if defined(__DragonFly__)
+// #include <uuid/uuid.h>
+#else
 #include <uuid/uuid.h>
+#endif
 
 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
