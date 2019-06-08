--- libnetdata/threads/threads.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:45:29.000000000 +0100
@@ -26,7 +26,7 @@
 // compatibility library functions
 
 pid_t gettid(void) {
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 
     return (pid_t)pthread_getthreadid_np();
 
