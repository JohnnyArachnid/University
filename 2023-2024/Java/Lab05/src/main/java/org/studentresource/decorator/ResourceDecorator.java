package org.studentresource.decorator;

import org.studentresource.StudentResource;

public abstract class ResourceDecorator implements StudentResource {
    protected StudentResource decoratedResource;
    public ResourceDecorator(StudentResource decoratedResource) {
        this.decoratedResource = decoratedResource;
    }
    public StudentResource getDecoratedResource(){ return this.decoratedResource; }
    public void setDecoratedResource(StudentResource decoratedResource){ this.decoratedResource = decoratedResource; }
    @Override
    public String getId() { return decoratedResource.getId();}
    @Override
    public String getName(){ return decoratedResource.getName(); }
    @Override
    public void setId(String id){ this.decoratedResource.setId(id); }
    @Override
    public void setName(String name){ this.decoratedResource.setName(name); }

    // Implement all necessary methods from StudentResource
    // Override methods to add additional behaviors
}
