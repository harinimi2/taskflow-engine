/**
 * @file ipc.h
 * @author Harini MINA
 * @brief En-tête du module IPC (Tubes / FIFOs) pour TaskFlow Engine.
 * @date 2026-10-23
 */

#ifndef IPC_H
#define IPC_H

#include <stdio.h>
#include <stdlib.h>

// pour les read(), xrite(), close()
#include <unistd.h>

// pour les mkfifo() et les permissions de fichier
#include <sys/types.h>
#include <sys/stat.h>

// pour les drapeaux d'ouverture de fichiers
#include <fcntl.h>

// pour afficher les erreurs systeme perror()
#include <errno.h>

// ici le tube (fifo) est un canal de communication synchro entre plusieurs tâches
int create_fifo(const char *fifo_path); // pour créer et init un tube grâce à int mkfifo(const char *pathname, mode_t mode)
int open_fifo_read(const char *fifo_path); // ouvre le tube en mode lecture
int open_fifo_write(const char *fifo_path); // ouvre le tube en mode écriture
int close_fifo(int fd); // fermer le tube
ssize_t write_fifo(int fd, const void *buf, size_t count); // pour écrire dans un tube
ssize_t read_fifo(int fd, void *buf, size_t count); // pour lire depuis un tube

#endif // IPC_H