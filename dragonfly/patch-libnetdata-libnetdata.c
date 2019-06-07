diff --git a/libnetdata/libnetdata.c b/libnetdata/libnetdata.c
index 095c38c2..b00870ea 100644
--- a/libnetdata/libnetdata.c
+++ b/libnetdata/libnetdata.c
@@ -5,7 +5,7 @@
 #ifdef __APPLE__
 #define INHERIT_NONE 0
 #endif /* __APPLE__ */
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 #    define O_NOATIME     0
 #    define MADV_DONTFORK INHERIT_NONE
 #endif /* __FreeBSD__ || __APPLE__*/
@@ -1179,7 +1179,7 @@ int recursively_delete_dir(const char *path, const char *reason) {
 
 static int is_virtual_filesystem(const char *path, char **reason) {
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) 
     (void)path;
     (void)reason;
 #else
