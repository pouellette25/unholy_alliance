// Copyright Dragon Sword Entertainment 2018

#include "HttpService.h"
#include "Runtime/Json/Public/Json.h"
#include "Engine.h"

UHttpService* UHttpService::Instance = NULL;

UHttpService::UHttpService() { Instance = this; UE_LOG(LogTemp, Warning, TEXT("HttpService Constructor"));
}

UHttpService& UHttpService::GetInstance()
{
	if (!ensure(Instance))
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating HttpService Instance"));
		UHttpService();
	}

	UE_LOG(LogTemp, Warning, TEXT("Returning Instance"));

	return *Instance;
}

void UHttpService::Get(const FString &Url)
{
	UE_LOG(LogTemp, Warning, TEXT("Service Get"));
	
	auto Http = &FHttpModule::Get();
	Http->SetHttpTimeout(300.0f);

	auto Request = Http->CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UHttpService::OnResponseReceived);
	Request->SetURL(Url);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();
}

void UHttpService::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	UE_LOG(LogTemp, Warning, TEXT("Request finished"));
	UE_LOG(LogTemp, Warning, TEXT("Request: %s"), *Response->GetContentAsString());
	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	//Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		UE_LOG(LogTemp, Warning, TEXT("Request reading"));
		//Get the value of the json object by field name
		auto value1 = JsonObject->GetStringField("value1");

		//Output it to the engine
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, value1);

		UE_LOG(LogTemp, Warning, TEXT("%s"), *value1);
	}
}
