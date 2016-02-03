//Copyright(c) 2016 Viktor Kuropiatnyk "BoredEngineer"

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MMTBPFunctionLibrary.generated.h"

UCLASS()
class MMT_API UMMTBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	
	/**
	*	Get world-space component's transform. BodyInstance is used to retrive transform, its up-to date with physics sub-stepping.
	*	@param Target	Component's reference to get the transform for
	*	@return			Component's transform in world space
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MMT Get Transform -Comp"), Category = "MMT physics sub-stepping")
	static FTransform MMTGetTransformComponent(UPrimitiveComponent * Target);

	/**
	*	Get world-space actor's root component transform. BodyInstance is used to retrive transform, its up-to date with physics sub-stepping.
	*	@param Actor	Actor's reference to get the transform for
	*	@return			Actor's root component transform in world space
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MMT Get Transform -Actor"), Category = "MMT physics sub-stepping")
	static FTransform MMTGetTransformActor(AActor* Actor);

	/**
	*	Add a force to a component. Can apply force during physics sub-steps.
	*	@param Target		Component's reference to apply force to
	*	@param Force		Force vector to apply. Magnitude indicates strength of force.
	*	@param bAccelChange If true, Force is taken as a change in acceleration instead of a physical force (i.e. mass will have no affect).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MMT Add Force -Comp"), Category = "MMT physics sub-stepping")
	static void MMTAddForceComponent(UPrimitiveComponent* Target, const FVector& Force, bool bAccelChange);

	/**
	*	Add a force to a component at a particular location. Can apply force during physics sub-steps.
	*	@param Target		Component's reference to apply force to
	*	@param Force		Force vector to apply. Magnitude indicates strength of force.
	*	@param Location		Location to apply force, in world space.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MMT Add Force At Location -Comp"), Category = "MMT physics sub-stepping")
	static void MMTAddForceAtLocationComponent(UPrimitiveComponent* Target, const FVector& Force, const FVector& Location);

private:
	static FBodyInstance* GetBodyInstance(UPrimitiveComponent* PrimitiveComponent);
};