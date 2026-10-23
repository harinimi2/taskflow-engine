/**
 * @file ipc.c
 * @author Harini MINA
 * @brief Implémentation du module de communication inter-processus (IPC) 
 *        par tubes nommés (FIFO) pour le projet TaskFlow Engine
 * @date 2026-10-23
 */


// Cette partie sert à gérer la communication entre les tâches et donc de gérer des signaux
// L'objectif ici est de permettre à notre moteur d'envoyer ou de recevoir des commandes/données via des tubes de communication

#include "ipc.h"

// création du tube fifo de communication
int create_fifo(const char* fifo_path) {
    return mkfifo(fifo_path,0644); // mode_t 0644 
    // 0 pour le format octal
    // 6 pour les droits lecture et écriture pour LE PROP du fichier
    // 4 pour les droits UNIQUEMENT en lecture pour les autres utilisateurs
}

// pour ouvrir ce tube fifo en mode lecture seule
int open_fifo_read(const char *fifo_path) {
    // int open(const char *pathname, int flags)
    return open(fifo_path, O_RDONLY);
    // le flag pour la lecture seule est : O_RDONLY
}

// pour ouvrir ce tube fifo en mode lecture seule
int open_fifo_write(const char *fifo_path) {
    // int open(const char *pathname, int flags)
    return open(fifo_path, O_WRONLY);
    // le flag pour l'écriture seule est : O_WRONLY
}


// pour fermer ce tube fifo (la fermeture est universelle donc pas besoin de mode)
int close_fifo(int fd) {
    return close(fd);
}

