diff --git a/collectors/proc.plugin/ipc.c b/collectors/proc.plugin/ipc.c
index 048fe74a..57f93727 100644
--- a/collectors/proc.plugin/ipc.c
+++ b/collectors/proc.plugin/ipc.c
@@ -2,10 +2,17 @@
 
 #include "plugin_proc.h"
 
+#ifdef __DragonFly__
+#define _KERNEL_STRUCTURES
+#define SEM_INFO 0
+#endif
 #include <sys/sem.h>
 #include <sys/msg.h>
 #include <sys/shm.h>
 
+#ifdef __DragonFly__
+#undef _KERNEL_STRUCTURES
+#endif
 
 #ifndef SEMVMX
 #define SEMVMX  32767  /* <= 32767 semaphore maximum value */
