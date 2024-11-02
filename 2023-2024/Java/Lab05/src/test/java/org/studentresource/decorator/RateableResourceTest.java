package org.studentresource.decorator;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.studentresource.StudyMaterial;
import org.studentresource.decorator.RateableResource;

import static org.junit.jupiter.api.Assertions.*;

class RateableResourceTest {
    private RateableResource rateableResource;

    @BeforeEach
    void setUp() {
        StudyMaterial studyMaterial = new StudyMaterial("SM101", "Introduction to Algorithms");
        rateableResource = new RateableResource(studyMaterial);
    }

    @Test
    void addAndGetCommentTest() {
        double rating = 5.0;
        rateableResource.setRating(rating);

        assertEquals(rating, rateableResource.getRating(), "The rating should match the added one.");
    }
}
