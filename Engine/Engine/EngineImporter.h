#pragma once

#ifndef ENGINEIMPORTER_H
#define ENGINEIMPORTER_H
#include <string>
#include "Importer.hpp"
using namespace std;
using namespace Assimp;
class EngineImporter 
{
private:
    Importer* assimpImporter = new Importer();
public:
    Importer* GetAssimpImporter();
    ~EngineImporter();
};
#endif