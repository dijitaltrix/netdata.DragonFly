--- libnetdata/os.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:51:36.000000000 +0100
@@ -20,7 +20,7 @@
         }
 
         return processors;
-#elif __FreeBSD__
+#elif (__FreeBSD__ || __DragonFly__)
     int32_t tmp_processors;
 
         if (unlikely(GETSYSCTL_BY_NAME("hw.ncpu", tmp_processors))) {
@@ -72,7 +72,7 @@
         // we use the number defined in bsd/sys/proc_internal.h in XNU sources
         pid_max = 99999;
         return pid_max;
-#elif __FreeBSD__
+#elif (__FreeBSD__ || __DragonFly__)
     int32_t tmp_pid_max;
 
         if (unlikely(GETSYSCTL_BY_NAME("kern.pid_max", tmp_pid_max))) {
