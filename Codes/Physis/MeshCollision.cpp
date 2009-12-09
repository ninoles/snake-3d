/*
 * MeshCollision.cpp
 *
 *  Created on: 03/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Physis/MeshCollision.h"

using namespace irr;
using namespace scene;
using namespace physis;

MeshCollision::MeshCollision(NewtonWorld *__nWorld,	base::FrameSceneNode *__node){

	_nWorld = __nWorld;
	_node = __node;
	_meshBuffer = NULL;

}

MeshCollision::~MeshCollision(){
}

u32 MeshCollision::getVerticesFromMesh(){

	u32 numberVertices = 0;

	for(int indexVertices = 0; indexVertices < ((IMeshSceneNode*)_node->getSceneNode())->getMesh()->getMeshBufferCount(); indexVertices++)
		numberVertices += ((IMeshSceneNode*)_node->getSceneNode())->getMesh()->getMeshBuffer(indexVertices)->getVertexCount();

	_vertices = new float[numberVertices * 3];

	return numberVertices;

}

void MeshCollision::copyToMeshBuffer(){

	video::S3DVertex *vertex;
	int count = 0;

	for(int indexVertices = 0; indexVertices < ((IMeshSceneNode*)_node->getSceneNode())->getMesh()->getMeshBufferCount(); indexVertices++){

		_meshBuffer = ((IMeshSceneNode*)_node->getSceneNode())->getMesh()->getMeshBuffer(indexVertices);

		vertex = (video::S3DVertex*)_meshBuffer->getVertices();

		for(int k = 0; k < _meshBuffer->getVertexCount(); k++){
			_vertices[count++] = vertex[k].Pos.X;
			_vertices[count++] = vertex[k].Pos.Y;
			_vertices[count++] = vertex[k].Pos.Z;
		}

	}
}

void MeshCollision::createCollision(){

	u32 numberV = getVerticesFromMesh();
	copyToMeshBuffer();

	_newtonCol = NewtonCreateConvexHull(_nWorld, numberV, _vertices, sizeof(float)*3, 0.1f, 0, NULL);
	_node->setCollisionNode(_newtonCol);
}

NewtonCollision* MeshCollision::getCollisionNode(){
	return _newtonCol;
}
