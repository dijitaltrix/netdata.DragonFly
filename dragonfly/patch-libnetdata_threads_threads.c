--- libnetdata/threads/threads.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 12:07:07.000000000 +0100
@@ -26,7 +26,7 @@
 // compatibility library functions
 
 pid_t gettid(void) {
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
 
     return (pid_t)pthread_getthreadid_np();

@@ -44,7 +44,7 @@

     return (pid_t)syscall(SYS_gettid);

-#endif /* __FreeBSD__, __APPLE__*/
+#endif /* __APPLE__, __DragonFly__, __FreeBSD__*/
}

// ----------------------------------------------------------------------------