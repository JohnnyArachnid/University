package org.studentresource;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

// This class should manage different student resources
public class StudentResourceManager<T extends StudentResource> {
    private List<T> resources;
    public StudentResourceManager(){ this.resources = new ArrayList<>(); }
    public boolean isResourcesEmpty() { return resources.isEmpty(); }
    public int resourcesSize() { return resources.size(); }
    public void resourcesClear() { resources.clear(); }
    public void addResource(T resource){ resources.add(resource); }
    public T getResourceById(String id){
        if (isResourcesEmpty()) { return null; }
        for(T resource : resources) {
            if (Objects.equals(resource.getId(), id)) {
                return resource;
            }
        }
        return null;
    }
    public T getResourceByName(String name){
        if (isResourcesEmpty()) { return null; }
        for(T resource : resources) {
            if (Objects.equals(resource.getName(), name)) {
                return resource;
            }
        }
        return null;
    }
    public int findResourceById(String id){
        if (resources.isEmpty()) { return -1; }
        T resource = getResourceById(id);
        if (resource != null) { return resources.indexOf(resource); }
        return -1;
    }
    public int findResourceByName(String name){
        if (resources.isEmpty()) { return -1; }
        T resource = getResourceByName(name);
        if (resource != null) { return resources.indexOf(resource); }
        return -1;
    }
    public void removeResourceById(String id){
        if (resources.isEmpty()) { return; }
        T resource = getResourceById(id);
        if (resource != null) { resources.remove(resource); }
        else { System.out.println("None elements to erase with declared id!"); }
    }
    public void removeResourceByName(String name){
        if (resources.isEmpty()) { return; }
        T resource = getResourceByName(name);
        if (resource != null) { resources.remove(resource); }
        else { System.out.println("None elements to erase with declared id!"); }
    }

    // Implement methods to manage resources (add, remove, find, etc.)
}
