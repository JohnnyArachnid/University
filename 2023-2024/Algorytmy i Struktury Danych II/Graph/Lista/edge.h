// Autor: Daniel Szarek i Pan Tomek :)

#pragma once

struct edge
{
    int vertex_Index1;
    int vertex_Index2;
    float waga;

public:
    edge(int i_Vertex_Index1, int i_Vertex_Index2);
    edge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight);
    bool operator==(const edge& other) const {
        return (vertex_Index1 == other.vertex_Index1) && (vertex_Index2 == other.vertex_Index2);
    } 
};


