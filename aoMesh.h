//
/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOMESH_H
#define AOMESH_H
#include "vector3.h"
//#include "vector.h"
#include <vector>
namespace ao
{
namespace graphics
{

//
// Mesh
// (class template)
// ----------
// +	Vertex:typedef Vector3
// +	Mesh()
// +	Mesh(Vertex const*verticies,int vertexCount,int const*indicies,int indexCount)
// +	~Mesh():virtual
// +	set(Vertex const*verticies,int vertexCount,int const*indicies,int indexCount): void
// +	addVertex(Vertex const &vertex): int
// +	addPrimative(int i, int j, int k): int
// +	getVertexCount()const:int
// +	getVertex(int i) const:Vertex const &
// +	getVertex(int i):Vertex&
// +	clear():void
// +	getIndexcount()const:int
// +	getIndex(int i) const:int
// ----------
// -	m_Verticies: Vector<Vertex>
// -	m_Indicies: Vector<int>
// ----------
//
class Mesh
{
public:
    //typedef vector3 Vertex;
private:
    Vector<vector3> m_Verticies;
    Vector<int> m_Indicies;
public:
    Mesh();
    Mesh(Vertex const*verticies,int vertexCount,int const*indicies,int indexCount)
    {
        clear();
        for(int i=0; i<vertexCount; i++)
        {
            addVertex(verticies[i]);
        }
        for(int i=0; i<indexCount; i+=3)
        {
            addPrimative(indicies[i],indicies[i+1],indicies[i+2]);
        }
    }

    virtual ~Mesh();
    void set(Vertex const*verticies,int vertexCount,int const*indicies,int indexCount)
    {
        clear();
        for(int i=0; i<vertexCount; i++)
        {
            addVertex(verticies[i]);
        }
        for(int i=0; i<indexCount; i+=3)
        {
            addPrimative(indicies[i],indicies[i+1],indicies[i+2]);
        }
    }
    int addVertex(Vertex const &vertex)
    {
        int index=(int) m_Verticies.size();
        m_Verticies.push_back(vertex);
        return index;
    }
    int addPrimative(int i, int j, int k)
    {
        int index=(int) m_Indicies.size();
        m_Indicies.push_back(i);
        m_Indicies.push_back(j);
        m_Indicies.push_back(k);
        return index;
    }
    int getVertexCount()const
    {
        return (int) m_Verticies.size();
    }
    Vertex const &getVertex(int i) const
    {
        return m_Verticies[i];
    }
    Vertex&getVertex(int i)
    {
        return m_Verticies[i];
    }
    void clear()
    {
        m_Verticies.clear();
        m_Indicies.clear();
    }
    int getIndexcount()const
    {
        return (int) m_Indicies.size();
    }
    int getIndex(int i) const
    {
        return m_Indicies[i];
    }
};
}
}
#endif
