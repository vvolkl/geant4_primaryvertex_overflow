
#include "G4Event.hh"
#include "G4PrimaryVertex.hh"

int main() {
    G4cout << "Starting Test... " << G4endl;
    const int numVertices = 1000000;
    G4PrimaryVertex* vertexlist[numVertices];
    vertexlist[0] = new G4PrimaryVertex();
    for (int i = 1; i < numVertices; ++i) {
      vertexlist[i] = new G4PrimaryVertex();
      vertexlist[i]->SetNext(vertexlist[i-1]);
    }
    G4cout << "Linked vertices created." << G4endl;
    // due to its implementation as a linked list ( SetNext ), 
    // deleting the n-th vertex 
    // recursively deletes all vertices down to vertex 0
    // depending on stack-size, this will eventually result in a
    // stack overflow
    delete vertexlist[100000];
    G4cout << "Vertex destructor called." << G4endl;
    return 0;
}

