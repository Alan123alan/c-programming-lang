#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
} Address;

typedef struct{
	Address rows[MAX_ROWS];
} Database;

typedef struct{
	FILE *file;
	Database *db;
} Connection;

void die(const char *message){
	if(errno){
		perror(message);
	}else{
		printf("Error: %s\n", message);
	}
	exit(1);
}

void Address_print(Address *addr){
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(Connection *conn){
	int rc = fread(conn->db, sizeof(Database), 1, conn->file);
	if(rc != 1){
		die("Failed to load database.\n");
	}
}

Connection *Database_open(const char *filename, char mode){
	Connection *conn = malloc(sizeof(Connection));
	if(!conn){
		die("Memory error");
	}
	Database *db = malloc(sizeof(Database));
	if(mode == 'c'){
		conn->file = fopen(filename, "w");	
	}else{
		conn->file = fopen(filename, "r+");
		if(conn->file){
			Database_load(conn);
		}
	}
	if(!conn->file){
		die("Failed to open the file.\n");
	}
	return conn;	
}

void Database_close(Connection *conn){
	if(conn){
		if(conn->file){
			fclose(conn->file);
		}
		if(conn->db){
			free(conn->db);
		}
		free(conn);
	}
}
