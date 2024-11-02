package org.studentresource;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StudentResourceManagerTest {
    private StudentResourceManager<Course> manager1;
    private StudentResourceManager<StudyMaterial> manager2;

    @BeforeEach
    void setUp() {
        manager1 = new StudentResourceManager<>();
        manager2 = new StudentResourceManager<>();
    }

    @Test
    void addAndRetrieveResourceTest() {
        Course course1 = new Course("CS101", "Introduction to Computer Science");
        manager1.addResource(course1);
        Course course2 = new Course("CS102", "Java Programing Language");
        manager1.addResource(course2);
        Course course3 = new Course("CS103", "English Language");
        manager1.addResource(course3);
        StudyMaterial studyMaterial1 = new StudyMaterial("SM101", "Introduction to Algorithms");
        manager2.addResource(studyMaterial1);
        StudyMaterial studyMaterial2 = new StudyMaterial("SM102", "Fundamentals of Physics");
        manager2.addResource(studyMaterial2);
        Course retrieved1 = manager1.getResourceById("CS101");
        Course retrieved2 = manager1.getResourceById("CS104");
        Course retrieved3 = manager1.getResourceByName("C++ Programing Language");
        StudyMaterial retrieved4 = manager2.getResourceByName("Fundamentals of Physics");
        assertNotNull(retrieved1, "Retrieved course should not be null.");
        assertNull(retrieved2, "Course with CS104 id doesn't exist");
        assertNull(retrieved3, "Study Material with C++ Programing Language name doesn't exist");
        assertEquals("CS101", retrieved1.getId(), "Course id should match.");
        assertEquals("Introduction to Computer Science", retrieved1.getName(), "Course name should match.");
        assertEquals("SM102", retrieved4.getId(), "Study Material id should match.");
        assertEquals("Fundamentals of Physics", retrieved4.getName(), "Study Material name should match.");
    }
    @Test
    void removeAndClearResourceTest() {
        Course course1 = new Course("CS101", "Introduction to Computer Science");
        manager1.addResource(course1);
        Course course2 = new Course("CS102", "Java Programing Language");
        manager1.addResource(course2);
        Course course3 = new Course("CS103", "English Language");
        manager1.addResource(course3);
        StudyMaterial studyMaterial1 = new StudyMaterial("SM101", "Introduction to Algorithms");
        manager2.addResource(studyMaterial1);
        StudyMaterial studyMaterial2 = new StudyMaterial("SM102", "Fundamentals of Physics");
        manager2.addResource(studyMaterial2);
        manager1.removeResourceById("CS102");
        assertEquals(2, manager1.resourcesSize(), "Remove resource by Id isn't working correct");
        manager2.resourcesClear();
        assertTrue(manager2.isResourcesEmpty(), "Resources clear and empty aren't working correct");
    }
    @Test
    void findResourceTest() {
        Course course1 = new Course("CS101", "Introduction to Computer Science");
        manager1.addResource(course1);
        Course course2 = new Course("CS102", "Java Programing Language");
        manager1.addResource(course2);
        Course course3 = new Course("CS103", "English Language");
        manager1.addResource(course3);
        StudyMaterial studyMaterial1 = new StudyMaterial("SM101", "Introduction to Algorithms");
        manager2.addResource(studyMaterial1);
        StudyMaterial studyMaterial2 = new StudyMaterial("SM102", "Fundamentals of Physics");
        manager2.addResource(studyMaterial2);
        int index1 = manager1.findResourceById("CS102");
        assertEquals(1, index1, "Find resource isn't working correct");
        manager2.removeResourceByName("Fundamentals of Physics");
        int index2 = manager2.findResourceByName("Introduction to Algorithms");
        assertEquals(0, index2, "Find resource isn't working correct");
        int index3 = manager1.findResourceById("CS104");
        assertEquals(-1, index3, "Find resource isn't working correct");
    }

//    @Test

    // Add more tests to cover all functionalities
}
