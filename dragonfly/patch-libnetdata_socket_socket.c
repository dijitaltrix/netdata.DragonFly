--- libnetdata/socket/socket.c	2019-05-22 17:46:15.000000000 +0100
+++ -	2019-06-08 11:45:29.000000000 +0100
@@ -944,7 +944,7 @@
             strncpyz(client_port, "UNKNOWN", portsize - 1);
         }
 
-#ifdef __FreeBSD__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
         if(((struct sockaddr *)&sadr)->sa_family == AF_LOCAL)
             strncpyz(client_ip, "localhost", ipsize);
 #endif
