// Copyright blackw 2015-2020

#pragma once

#include "EngineMinimal.h"
#include "Networking.h"
#include "VdNetCommon.h"
#include "VdServerComponent.generated.h"



class ASandboxTerrainController;

/**
*
*/
UCLASS()
class UNREALSANDBOXTERRAIN_API UVdServerComponent : public UVdNetworkComponent
{
	GENERATED_UCLASS_BODY()

public:

	virtual void BeginDestroy();

	virtual void BeginPlay();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

public:

	bool OnConnectionAccepted(FSocket* SocketPtr, const FIPv4Endpoint& Endpoint);

	template <typename... Ts>
	void SendToAllClients(uint32 OpCode, Ts... Args);

private:

	bool SendVdByIndex(FSocket* SocketPtr, TVoxelIndex& VoxelIndex);

	TMap<FString, FSocket*> ConnectedClientsMap;

	FTcpListener* TcpListenerPtr;

	ASandboxTerrainController* GetTerrainController() {
		return (ASandboxTerrainController*)GetAttachmentRootActor();
	};
	
};
