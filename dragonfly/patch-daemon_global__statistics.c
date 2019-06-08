--- daemon/global_statistics.c	2019-05-22 09:46:14.000000000 +0100
+++ -	2019-06-08 11:07:43.000000000 +0100
@@ -192,7 +192,7 @@
         static RRDDIM *rd_cpu_thread_user = NULL,
                       *rd_cpu_thread_system = NULL;
 
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
         if (unlikely(!st_cpu_thread)) {
             st_cpu_thread = rrdset_create_localhost(
                     "netdata"
