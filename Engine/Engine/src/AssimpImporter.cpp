#include "AssimpImporter.h"

#include <Importer.hpp>      // C++ importer interface
#include <scene.h>           // Output data structure
#include <postprocess.h>     // Post processing flags

#include "Mesh.h"

#include <iostream>

using namespace  Assimp;
using namespace std;

bool AssimpImporter::DoTheImportThing(const std::string& pFile)
{
	// Create an instance of the Importer class
	Assimp::Importer importer;
	// And have it read the given file with some example postprocessing
	// Usually - if speed is not the most important aspect for you - you'll
	// probably to re quest more postprocessing than we do in this example.
	const aiScene* scene = importer.ReadFile(pFile,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);
	// If the import failed, report it
	if (!scene)
	{
		std::cout << (importer.GetErrorString()) << std::endl;
		return false;
	}

	std::cout << "Cargo el modelo" << std::endl;
	// Now we can access the file's contents.
	//DoTheSceneProcessing(scene);
	// We're done. Everything will be cleaned up by the importer destructor
	return true;
}

const aiScene* AssimpImporter::ImportModel(std::string path)
{
	Importer import;
	const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate /*| aiProcess_FlipUVs*/);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
		return nullptr;
	}

	return scene;
}