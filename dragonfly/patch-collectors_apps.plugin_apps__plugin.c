--- collectors/apps.plugin/apps_plugin.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 12:07:07.000000000 +0100
@@ -68,7 +68,7 @@
 
 // ----------------------------------------------------------------------------
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
 #include <sys/user.h>
 #endif
 
@@ -84,7 +84,7 @@
 // set this to 1
 // when set to 0, apps.plugin builds a sort list of processes, in order
 // to process children processes, before parent processes
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
 #define ALL_PIDS_ARE_READ_INSTANTLY 1
 #else
 #define ALL_PIDS_ARE_READ_INSTANTLY 0
@@ -122,7 +122,7 @@
 static int
         update_every = 1,
         enable_guest_charts = 0,
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
         enable_file_charts = 0,
 #else
         enable_file_charts = 1,
@@ -285,7 +285,7 @@
 struct pid_fd {
     int fd;
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     ino_t inode;
     char *filename;
     uint32_t link_hash;
@@ -368,7 +368,7 @@
     kernel_uint_t status_rssfile;
     kernel_uint_t status_rssshmem;
     kernel_uint_t status_vmswap;
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     ARL_BASE *status_arl;
 #endif
 
@@ -766,7 +766,7 @@
     if(p->prev) p->prev->next = p->next;
 
     // free the filename
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     {
         size_t i;
         for(i = 0; i < p->fds_size; i++)
@@ -779,7 +779,7 @@
     freez(p->fds_dirname);
     freez(p->stat_filename);
     freez(p->status_filename);
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     arl_free(p->status_arl);
 #endif
     freez(p->io_filename);
@@ -802,7 +802,7 @@
                 p->log_thrown |= log;
                 switch(log) {
                     case PID_LOG_IO:
-                        #ifdef __FreeBSD__
+                        #if (defined(__DragonFly__) || defined(__FreeBSD__))
                         error("Cannot fetch process %d I/O info (command '%s')", p->pid, p->comm);
                         #else
                         error("Cannot process %s/proc/%d/io (command '%s')", netdata_configured_host_prefix, p->pid, p->comm);
@@ -810,7 +810,7 @@
                         break;
 
                     case PID_LOG_STATUS:
-                        #ifdef __FreeBSD__
+                        #if (defined(__DragonFly__) || defined(__FreeBSD__))
                         error("Cannot fetch process %d status info (command '%s')", p->pid, p->comm);
                         #else
                         error("Cannot process %s/proc/%d/status (command '%s')", netdata_configured_host_prefix, p->pid, p->comm);
@@ -818,7 +818,7 @@
                         break;
 
                     case PID_LOG_CMDLINE:
-                        #ifdef __FreeBSD__
+                        #if (defined(__DragonFly__) || defined(__FreeBSD__))
                         error("Cannot fetch process %d command line (command '%s')", p->pid, p->comm);
                         #else
                         error("Cannot process %s/proc/%d/cmdline (command '%s')", netdata_configured_host_prefix, p->pid, p->comm);
@@ -826,7 +826,7 @@
                         break;
 
                     case PID_LOG_FDS:
-                        #ifdef __FreeBSD__
+                        #if (defined(__DragonFly__) || defined(__FreeBSD__))
                         error("Cannot fetch process %d files (command '%s')", p->pid, p->comm);
                         #else
                         error("Cannot process entries in %s/proc/%d/fd (command '%s')", netdata_configured_host_prefix, p->pid, p->comm);
@@ -892,7 +892,7 @@
 static inline int read_proc_pid_cmdline(struct pid_stat *p) {
     static char cmdline[MAX_CMDLINE + 1];
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     size_t i, bytes = MAX_CMDLINE;
     int mib[4];
 
@@ -955,7 +955,7 @@
 
 // ----------------------------------------------------------------------------
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
 struct arl_callback_ptr {
     struct pid_stat *p;
     procfile *ff;
@@ -1029,7 +1029,7 @@
 
     aptr->p->status_rssshmem = str2kernel_uint_t(procfile_lineword(aptr->ff, aptr->line, 1));
 }
-#endif // !__FreeBSD__
+#endif // !__DragonFly__, !__FreeBSD__
 
 static inline int read_proc_pid_status(struct pid_stat *p, void *ptr) {
     p->status_vmsize           = 0;
@@ -1039,7 +1039,7 @@
     p->status_rssshmem         = 0;
     p->status_vmswap           = 0;
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     struct kinfo_proc *proc_info = (struct kinfo_proc *)ptr;
 
     p->uid                  = proc_info->ki_uid;
@@ -1108,7 +1108,7 @@
 static inline int read_proc_pid_stat(struct pid_stat *p, void *ptr) {
     (void)ptr;
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     struct kinfo_proc *proc_info = (struct kinfo_proc *)ptr;
 
     if (unlikely(proc_info->ki_tdflags & TDF_IDLETD))
@@ -1139,7 +1139,7 @@
     p->stat_collected_usec = now_monotonic_usec();
     calls_counter++;
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     char *comm          = proc_info->ki_comm;
     p->ppid             = proc_info->ki_ppid;
 #else
@@ -1171,7 +1171,7 @@
         assign_target_to_pid(p);
     }
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     pid_incremental_rate(stat, p->minflt,  (kernel_uint_t)proc_info->ki_rusage.ru_minflt);
     pid_incremental_rate(stat, p->cminflt, (kernel_uint_t)proc_info->ki_rusage_ch.ru_minflt);
     pid_incremental_rate(stat, p->majflt,  (kernel_uint_t)proc_info->ki_rusage.ru_majflt);
@@ -1271,7 +1271,7 @@
 
 static inline int read_proc_pid_io(struct pid_stat *p, void *ptr) {
     (void)ptr;
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     struct kinfo_proc *proc_info = (struct kinfo_proc *)ptr;
 #else
     static procfile *ff = NULL;
@@ -1295,7 +1295,7 @@
     p->last_io_collected_usec = p->io_collected_usec;
     p->io_collected_usec = now_monotonic_usec();
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     pid_incremental_rate(io, p->io_storage_bytes_read,       proc_info->ki_rusage.ru_inblock);
     pid_incremental_rate(io, p->io_storage_bytes_written,    proc_info->ki_rusage.ru_oublock);
 #else
@@ -1320,7 +1320,7 @@
 
     return 1;
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
 cleanup:
     p->io_logical_bytes_read        = 0;
     p->io_logical_bytes_written     = 0;
@@ -1333,7 +1333,7 @@
 #endif
 }
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
 static inline int read_global_time() {
     static char filename[FILENAME_MAX + 1] = "";
     static procfile *ff = NULL;
@@ -1657,7 +1657,7 @@
 static inline void clear_pid_fd(struct pid_fd *pfd) {
     pfd->fd = 0;
 
-    #ifndef __FreeBSD__
+    #if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     pfd->link_hash = 0;
     pfd->inode = 0;
     pfd->cache_iterations_counter = 0;
@@ -1693,7 +1693,7 @@
     size_t i = first;
 
     while(pfd < pfdend) {
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
         pfd->filename = NULL;
 #endif
         clear_pid_fd(pfd);
@@ -1704,7 +1704,7 @@
 
 static inline int read_pid_file_descriptors(struct pid_stat *p, void *ptr) {
     (void)ptr;
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     int mib[4];
     size_t size;
     struct kinfo_file *fds;
@@ -2327,7 +2327,7 @@
 static int collect_data_for_all_processes(void) {
     struct pid_stat *p = NULL;
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     int i, procnum;
 
     static size_t procbase_size = 0;
@@ -2407,7 +2407,7 @@
 #endif
     }
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     for (i = 0 ; i < procnum ; ++i) {
         pid_t pid = procbase[i].ki_pid;
         collect_data_for_pid(pid, &procbase[i]);
@@ -3232,7 +3232,7 @@
     }
     send_END();
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     send_BEGIN(type, "swap", dt);
     for (w = root; w ; w = w->next) {
         if(unlikely(w->exposed && w->processes))
@@ -3255,7 +3255,7 @@
     }
     send_END();
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     send_BEGIN(type, "lreads", dt);
     for (w = root; w ; w = w->next) {
         if(unlikely(w->exposed && w->processes))
@@ -3384,7 +3384,7 @@
         }
     }
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
     fprintf(stdout, "CHART %s.swap '' '%s Swap Memory' 'MiB' swap %s.swap stacked 20011 %d\n", type, title, type, update_every);
     for (w = root; w ; w = w->next) {
         if(unlikely(w->exposed))
@@ -3404,7 +3404,7 @@
             fprintf(stdout, "DIMENSION %s '' absolute 1 %llu\n", w->name, RATES_DETAIL);
     }
 
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     fprintf(stdout, "CHART %s.preads '' '%s Disk Reads' 'blocks/s' disk %s.preads stacked 20002 %d\n", type, title, type, update_every);
     for (w = root; w ; w = w->next) {
         if(unlikely(w->exposed))
@@ -3522,7 +3522,7 @@
             continue;
         }
 
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
         if(strcmp("fds-cache-secs", argv[i]) == 0) {
             if(argc <= i + 1) {
                 fprintf(stderr, "Parameter 'fds-cache-secs' requires a number as argument.\n");
@@ -3604,7 +3604,7 @@
                     " without-files     enable / disable reporting files, sockets, pipes\n"
                     "                   (default is enabled)\n"
                     "\n"
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
                     " fds-cache-secs N  cache the files of processed for N seconds\n"
                     "                   caching is adaptive per file (when a file\n"
                     "                   is found, it starts at 0 and while the file\n"
@@ -3616,7 +3616,7 @@
                     " version or -v or -V print program version and exit\n"
                     "\n"
                     , VERSION
-#ifndef __FreeBSD__
+#if (!defined(__DragonFly__) || !defined(__FreeBSD__))
                     , max_fds_cache_seconds
 #endif
             );
@@ -3756,7 +3756,7 @@
     time_t started_t = now_monotonic_sec();
 
     get_system_HZ();
-#ifdef __FreeBSD__
+#if (defined(__DragonFly__) || defined(__FreeBSD__))
     time_factor = 1000000ULL / RATES_DETAIL; // FreeBSD uses usecs
 #else
     time_factor = system_hz; // Linux uses clock ticks
