#include "EngineImporter.h"

Importer* EngineImporter::GetAssimpImporter()
{
	return assimpImporter;
}

EngineImporter::~EngineImporter()
{
	delete assimpImporter;
}
