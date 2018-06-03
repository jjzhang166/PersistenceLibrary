/*
 * Persistence Library / Protocols / TcpServer (linux)
 *
 * Copyright (c) 2016-2018 Ondrej Sterba <osterba@atlas.cz>
 *
 * https://github.com/embedded-tools/PersistenceLibrary
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 */

#ifndef TCPSERVER___H
#define TCPSERVER___H

#include "tcpserver_linux.h"
#include <pthread.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

class TcpClient;

class TcpServer
{	
public:

    typedef void (*ServerReceivedDataCallback)(TcpClient* client, const char* command, int commandLength);
    typedef void (*ClientConnectedCallback)   (const struct sockaddr_in& address);
    typedef void (*ClientDisconnectedCallback)(const struct sockaddr_in& address);    
    
	enum ServerState
	{		
		NotListening,
        Listening
	};    
      
private:
  
    struct sockaddr_in  m_serverAddress; 
    int                 m_maxConnections;
    int                 m_maxPacketSize;
    
    TcpClient**         m_tcpClients;    
	int                 m_socketHandle;
	ServerState         m_connectionState;
    
    pthread_t           m_threadHandle;
    bool                m_threadStopped;    
                
    static void* InternalThread(void* arg);    
    static void PacketReceivedFromClient(void* arg, const char* command, int commandLength);
    
public:
    
    TcpServer(int maxPacketSize=256, int maxConnections=10);
    ~TcpServer();
    
    
    bool Listen(int port);   
    void Stop();    
    
    int  GetMaxPacketSize(); 
    int  GetMaxConnections();   
    
    void SendData(int clientIndex, const char* data, int dataLength);
    void SendData(int clientIndex, const void* data, int dataLength);
	
	void ClientTerminated(TcpClient* client);
        
    ClientConnectedCallback    OnClientConnected;
    ClientDisconnectedCallback OnClientDisconnected;
    ServerReceivedDataCallback OnReceiveData;
    
};


#endif