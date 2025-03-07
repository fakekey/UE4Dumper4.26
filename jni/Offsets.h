#ifndef OFFSETS_H
#define OFFSETS_H

#include "Mem.h"

namespace Offsets {
    //Global
    kaddr GWorld;
    kaddr GNames;
    kaddr GUObjectArray;
    kaddr PointerSize;
    kaddr FUObjectItemPadd;
    kaddr FUObjectItemSize;
    //-----PUBG Lite-----//
    kaddr PGLEncSelect;
    kaddr PGLBlockSlice1;
    kaddr PGLBlockShift;
    kaddr PGLBlockSlice2;

    //---------SDK-----------//
    //---------4.23+---------//
    //Class: FNamePool
    kaddr FNameStride;
    kaddr GNamesToFNamePool;//NamePoolData, alignas(FNamePool)
    kaddr FNamePoolToCurrentBlock;
    kaddr FNamePoolToCurrentByteCursor;
    kaddr FNamePoolToBlocks;
    //Class: FNameEntry
    kaddr FNameEntryToLenBit;
    kaddr FNameEntryToString;
    //Class: UStruct
    kaddr UStructToChildProperties;
    //Class: FField
    kaddr FFieldToClass;
    kaddr FFieldToNext;
    kaddr FFieldToName;
    //---------4.18+---------//
    //Class: FNameEntry
    kaddr FNameEntryToNameString;
    //-----------------------//
    //Class: FUObjectArray
    kaddr FUObjectArrayToTUObjectArray;
    //Class: TUObjectArray
    kaddr TUObjectArrayToNumElements;
    //Class: UObject
    kaddr UObjectToInternalIndex;
    kaddr UObjectToClassPrivate;
    kaddr UObjectToFNameIndex;
    kaddr UObjectToOuterPrivate;
    //Class: UField
    kaddr UFieldToNext;
    //Class: UStruct
    kaddr UStructToSuperStruct;
    kaddr UStructToChildren;
    //Class: UFunction
    kaddr UFunctionToFunctionFlags;
    kaddr UFunctionToFunc;
    //Class: UProperty
    kaddr UPropertyToElementSize;
    kaddr UPropertyToPropertyFlags;
    kaddr UPropertyToOffsetInternal;
    //Class: UBoolProperty
    kaddr UBoolPropertyToFieldSize;
    kaddr UBoolPropertyToByteOffset;
    kaddr UBoolPropertyToByteMask;
    kaddr UBoolPropertyToFieldMask;
    //Class: UObjectProperty
    kaddr UObjectPropertyToPropertyClass;
    //Class: UClassProperty
    kaddr UClassPropertyToMetaClass;
    //Class: UInterfaceProperty
    kaddr UInterfacePropertyToInterfaceClass;
    //Class: UArrayProperty
    kaddr UArrayPropertyToInnerProperty;
    //Class: UMapProperty
    kaddr UMapPropertyToKeyProp;
    kaddr UMapPropertyToValueProp;
    //Class: USetProperty
    kaddr USetPropertyToElementProp;
    //Class: UStructProperty
    kaddr UStructPropertyToStruct;
    //Class: UWorld
    kaddr UWorldToPersistentLevel;
    //Class: ULevel
    kaddr ULevelToAActors;
    kaddr ULevelToAActorsCount;

    void initOffsets_32() {
        //Global
        PointerSize = 0x4;
        FUObjectItemPadd = 0x0;
        FUObjectItemSize = 0x10;

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x8;
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x8;
        //Class: UObject
        UObjectToInternalIndex = 0x8;
        UObjectToClassPrivate = 0xC;
        UObjectToFNameIndex = 0x10;
        UObjectToOuterPrivate = 0x18;
        //Class: UField
        UFieldToNext = 0x1C;
        //Class: UStruct
        UStructToSuperStruct = 0x20;
        UStructToChildren = 0x24;
        //Class: UFunction
        UFunctionToFunctionFlags = 0x58;
        UFunctionToFunc = 0x74;
        //Class: UProperty
        UPropertyToElementSize = 0x24;
        UPropertyToPropertyFlags = 0x28;
        UPropertyToOffsetInternal = 0x34;
        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x50;
        UBoolPropertyToByteOffset = 0x51;
        UBoolPropertyToByteMask = 0x52;
        UBoolPropertyToFieldMask = 0x53;
        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x50;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x54;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x54;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x50;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x50;
        UMapPropertyToValueProp = 0x54;
        //Class: USetProperty
        USetPropertyToElementProp = 0x50;
        //Class: UStructProperty
        UStructPropertyToStruct = 0x50;
        //Class: UWorld
        UWorldToPersistentLevel = 0x20;
        //Class: ULevel
        ULevelToAActors = 0x70;
        ULevelToAActorsCount = 0x74;
    }

    void patchUE423_32() {
        //Class: FNamePool
        FNameStride = 0x2;
        GNamesToFNamePool = 0x30;
        FNamePoolToCurrentBlock = 0x4;
        FNamePoolToCurrentByteCursor = 0x8;
        FNamePoolToBlocks = 0xC;
        //Class: FNameEntry
        FNameEntryToLenBit = 6;
        FNameEntryToString = 0x2;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x10;
        //Class: UStruct
        UStructToChildProperties = 0x28;
        //Class: FField
        FFieldToClass = 0x4;
        FFieldToNext = 0x10;
        FFieldToName = 0x14;
    }

    void patchCustom_32() {
        if (isPUBGLite()) {//GName Fix(0.22)
            PGLEncSelect = 0x4EEDD74;
            PGLBlockSlice1 = 0x4F6DE98;
            PGLBlockShift = 0x4F6DE89;
            PGLBlockSlice2 = 0x4F6DEB0;
        }
        if (isGameOfPeace()) {
            //Class: FNameEntry
            FNameEntryToNameString = 0xA;
            //Class: FUObjectArray
            FUObjectArrayToTUObjectArray = 0x70;
            //Class: TUObjectArray
            TUObjectArrayToNumElements = 0xC;
        }
    }

    void initOffsets_64() {
        //Global
        PointerSize = 0x8;
        FUObjectItemPadd = 0x0;
        FUObjectItemSize = 0x18;

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x10;
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0xC;
        //Class: UObject
        UObjectToInternalIndex = 0xC;
        UObjectToClassPrivate = 0x10;
        UObjectToFNameIndex = 0x18;
        UObjectToOuterPrivate = 0x20;
        //Class: UField
        UFieldToNext = 0x28;
        //Class: UStruct
        UStructToSuperStruct = 0x30;
        UStructToChildren = 0x38;
        //Class: UFunction
        UFunctionToFunctionFlags = 0x88;
        UFunctionToFunc = 0xB0;
        //Class: UProperty
        UPropertyToElementSize = 0x34;
        UPropertyToPropertyFlags = 0x38;
        UPropertyToOffsetInternal = 0x44;
        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x70;
        UBoolPropertyToByteOffset = 0x71;
        UBoolPropertyToByteMask = 0x72;
        UBoolPropertyToFieldMask = 0x73;
        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x70;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x78;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x78;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x70;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x70;
        UMapPropertyToValueProp = 0x78;
        //Class: USetProperty
        USetPropertyToElementProp = 0x70;
        //Class: UStructProperty
        UStructPropertyToStruct = 0x70;
        //Class: UWorld
        UWorldToPersistentLevel = 0x30;
        //Class: ULevel
        ULevelToAActors = 0x98;
        ULevelToAActorsCount = 0xA0;
    }

    void patchUE423_64() {
        //Class: FNamePool
        FNameStride = 0x2;
        GNamesToFNamePool = 0x30;
        FNamePoolToCurrentBlock = 0x8;
        FNamePoolToCurrentByteCursor = 0xC;
        FNamePoolToBlocks = 0x10;
        //Class: FNameEntry
        FNameEntryToLenBit = 6;
        FNameEntryToString = 0x2;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x14;
        //Class: UStruct
        UStructToChildProperties = 0x44;
        //Class: FField
        FFieldToClass = 0x8;
        FFieldToNext = 0x20;
        FFieldToName = 0x28;
    }

    void patchUE426_64() {
        //Class: UStruct
        UStructToChildProperties = 0x50; 
        UStructToSuperStruct = 0x40; 
        UStructToChildren = 0x48;

        //Class: UFunction
        UFunctionToFunctionFlags = 0xB0;
        UFunctionToFunc = 0xd8;

        //Class: UProperty
        UPropertyToElementSize = 0x3c;
        UPropertyToPropertyFlags = 0x40;
        UPropertyToOffsetInternal = 0x4c;

        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x70;
        UBoolPropertyToByteOffset = 0x71;
        UBoolPropertyToByteMask = 0x72; 
        UBoolPropertyToFieldMask = 0x73;

        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x78;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x78;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x78;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x78;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x78;
        UMapPropertyToValueProp = 0x80; 
        //Class: USetProperty
        USetPropertyToElementProp = 0x78;   //  UProperty*       ElementProp;                // +8
        //Class: UStructProperty
        UStructPropertyToStruct = 0x78;     //  class UScriptStruct* Struct;                 // +8
    }

    void patchCustom_64() {
        if (isPUBGSeries()) {
            if (!isPUBGLite()) {
                //Class: FNameEntry
                FNameEntryToNameString = 0xC;
            }
            //Class: ULevel
            ULevelToAActors = 0xA0;
            ULevelToAActorsCount = 0xA8;
        }
        if (isPUBGLite()) {//GName Fix(0.23)
            PGLEncSelect = 0x6F39BA4;
            PGLBlockSlice1 = 0x6F39F10;
            PGLBlockShift = 0x6F39EF1;
            PGLBlockSlice2 = 0x6F39F40;
        }
        if (isGameOfPeace()) {
            //Class: FNameEntry
            FNameEntryToNameString = 0xC;
            //Class: FUObjectArray
            FUObjectArrayToTUObjectArray = 0xB0;
            //Class: TUObjectArray
            TUObjectArrayToNumElements = 0x14;
            //Class: ULevel
            ULevelToAActors = 0xA0;
            ULevelToAActorsCount = 0xA8;
        }
        if (isPUBGNewState()) {
            FUObjectItemPadd = 0x8;//0x10//0x8//0x10
            //Class: FNamePool
            GNamesToFNamePool = 0x18A0;//0x24A8//0x3CE0
            //Class: FField
            FFieldToClass = 0x18;//0x18//0x10
            FFieldToNext = 0x10;//0x30//0x8//0x18
            FFieldToName = 0x8;//0x10//0x20
            //Class: FUObjectArray
            FUObjectArrayToTUObjectArray = 0x140;//0x58
            //Class: TUObjectArray
            TUObjectArrayToNumElements = -0xC;//0x14//0xC
            //Class: UObject
            UObjectToFNameIndex = 0x58;//0x60//0x8//0xC
            UObjectToClassPrivate = 0x38;//0x10//0x38//0x18
            UObjectToInternalIndex = 0x8;//0x50//0x58//0x38
            UObjectToOuterPrivate = 0x18;//0x30//0x10//0x48
            //Class: UField
            UFieldToNext = 0x68;
            //Class: UStruct
            UStructToChildren = 0x90;//0x90//0xB0//0xA0
            UStructToChildProperties = 0xE0;//0xE8//0xB8//0x98
            UStructToSuperStruct = 0x88;//0xC0//0xD8//0xC8
            //Class: UProperty
            UPropertyToElementSize = 0x38;//0x3C//0x38//0x3C
            UPropertyToPropertyFlags = 0x40;
            UPropertyToOffsetInternal = 0x4C;
            //Class: UFunction
            UFunctionToFunctionFlags = 0x10C;//0x10C//0xFC//0xF0
            UFunctionToFunc = 0xF8;//0x100//0x108//0xF8
            //Class: UBoolProperty
            UBoolPropertyToFieldSize = 0x78;
            UBoolPropertyToByteOffset = 0x79;
            UBoolPropertyToByteMask = 0x7A;
            UBoolPropertyToFieldMask = 0x7B;
            //Class: UObjectProperty
            UObjectPropertyToPropertyClass = 0x78;
            //Class: UClassProperty
            UClassPropertyToMetaClass = 0x80;
            //Class: UInterfaceProperty
            UInterfacePropertyToInterfaceClass = 0x80;
            //Class: UArrayProperty
            UArrayPropertyToInnerProperty = 0x78;
            //Class: UMapProperty
            UMapPropertyToKeyProp = 0x78;
            UMapPropertyToValueProp = 0x80;
            //Class: USetProperty
            USetPropertyToElementProp = 0x78;
            //Class: UStructProperty
            UStructPropertyToStruct = 0x78;
            //Class: UWorld
            UWorldToPersistentLevel = 0x70;
            //Class: ULevel
            ULevelToAActors = 0x220;//0xB0//0x140//0xB0
            ULevelToAActorsCount = 0x228;//0xB8//0x148//0xB8
        }
        if (isARKSurvival()) {
            //Class: UWorld
            UWorldToPersistentLevel = 0x58;
        }
        if (isFortnite()) {
            //Class: UStruct
            UStructToSuperStruct = 0x40;
            UStructToChildren = 0x48;
            UStructToChildProperties = 0x50;
            //Class: UProperty
            UPropertyToElementSize = 0x38;
            UPropertyToPropertyFlags = 0x40;
            UPropertyToOffsetInternal = 0x4C;
            //Class: UFunction
            UFunctionToFunctionFlags = 0xB0;
            UFunctionToFunc = 0xD8;
            //Class: UBoolProperty
            UBoolPropertyToFieldSize = 0x78;
            UBoolPropertyToByteOffset = 0x79;
            UBoolPropertyToByteMask = 0x7A;
            UBoolPropertyToFieldMask = 0x7B;
            //Class: UObjectProperty
            UObjectPropertyToPropertyClass = 0x78;
            //Class: UClassProperty
            UClassPropertyToMetaClass = 0x80;
            //Class: UInterfaceProperty
            UInterfacePropertyToInterfaceClass = 0x80;
            //Class: UArrayProperty
            UArrayPropertyToInnerProperty = 0x78;
            //Class: UMapProperty
            UMapPropertyToKeyProp = 0x78;
            UMapPropertyToValueProp = 0x80;
            //Class: USetProperty
            USetPropertyToElementProp = 0x78;
            //Class: UStructProperty
            UStructPropertyToStruct = 0x78;
        }
        if (isApexLegends()) {
            //Class: UStruct
            UStructToSuperStruct = 0x40;
            UStructToChildren = 0x48;
            UStructToChildProperties = 0x50;
            //Class: UProperty
            UPropertyToElementSize = 0x38;
            UPropertyToPropertyFlags = 0x40;
            UPropertyToOffsetInternal = 0x4C;
            //Class: UFunction
            UFunctionToFunctionFlags = 0xC0;
            UFunctionToFunc = 0xE8;
            //Class: UBoolProperty
            UBoolPropertyToFieldSize = 0x78;
            UBoolPropertyToByteOffset = 0x79;
            UBoolPropertyToByteMask = 0x7A;
            UBoolPropertyToFieldMask = 0x7B;
            //Class: UObjectProperty
            UObjectPropertyToPropertyClass = 0x78;
            //Class: UClassProperty
            UClassPropertyToMetaClass = 0x80;
            //Class: UInterfaceProperty
            UInterfacePropertyToInterfaceClass = 0x80;
            //Class: UArrayProperty
            UArrayPropertyToInnerProperty = 0x78;
            //Class: UMapProperty
            UMapPropertyToKeyProp = 0x78;
            UMapPropertyToValueProp = 0x80;
            //Class: USetProperty
            USetPropertyToElementProp = 0x78;
            //Class: UStructProperty
            UStructPropertyToStruct = 0x78;
        }
    }
}

#endif