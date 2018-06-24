// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "HttpService.generated.h"

UCLASS()
class UNHOLYALLIANCE_API UHttpService : public UObject
{
	GENERATED_BODY()

private:
	static UHttpService* Instance;

protected:
	UHttpService();
	
public:	
	static UHttpService& GetInstance();

	const FString GetUrl = "https://dragonswordent.com/api/test";

	void Get(const FString &Url);

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);	
};
