--- daemon/global_statistics.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:51:36.000000000 +0100
@@ -192,7 +192,7 @@
         static RRDDIM *rd_cpu_thread_user = NULL,
                       *rd_cpu_thread_system = NULL;
 
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
         if (unlikely(!st_cpu_thread)) {
             st_cpu_thread = rrdset_create_localhost(
                     "netdata"
