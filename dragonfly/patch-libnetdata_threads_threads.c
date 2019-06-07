diff --git a/libnetdata/threads/threads.c b/libnetdata/threads/threads.c
index 133d9a54..74bd1522 100644
--- a/libnetdata/threads/threads.c
+++ b/libnetdata/threads/threads.c
@@ -26,7 +26,7 @@ const char *netdata_thread_tag(void) {
 // compatibility library functions
 
 pid_t gettid(void) {
-#ifdef __FreeBSD__
+#ifdef defined(__FreeBSD__) || defined(__DragonFly__)
 
     return (pid_t)pthread_getthreadid_np();
 
@@ -44,7 +44,7 @@ pid_t gettid(void) {
 
     return (pid_t)syscall(SYS_gettid);
 
-#endif /* __FreeBSD__, __APPLE__*/
+#endif /* __FreeBSD__, __DragonFly__, __APPLE__*/
 }
 
 // ----------------------------------------------------------------------------
