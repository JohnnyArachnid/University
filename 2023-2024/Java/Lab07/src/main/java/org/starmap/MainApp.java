package org.starmap;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import org.starmap.controller.StarMapController;
import org.starmap.model.Constellation;
import org.starmap.model.Star;
import org.starmap.utils.DataWriter;
import org.starmap.view.StarMapView;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.FileChooser;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.io.File;

// Main application class for the star map
public class MainApp extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Stage stage = new Stage();
        stage.setTitle("Utility Window");
        StarMapController controller = new StarMapController("src/main/resources/stars.json");
        StarMapView view = new StarMapView(controller);
        Group root = new Group(); // Create Group container
        root.getChildren().add(view); // Add StarMapView to container
        VBox buttonsLayout = new VBox(20);
        Scene sceneButtons = new Scene(buttonsLayout, 300, 300);
        buttonsLayout.setAlignment(Pos.CENTER);
        Button constelationModify = new Button("Constelation modify");
        buttonsLayout.getChildren().add(constelationModify);
        Button starModify = new Button("Star modify");
        buttonsLayout.getChildren().add(starModify);
        Scene scene2 = new Scene(root, 1024, 768); // Create Scene with Group container
        Button numberLine = new Button("Draw Number Line");
        buttonsLayout.getChildren().add(numberLine);
        Line xAxis = new Line(0, 384, 1024, 384);
        Line yAxis = new Line(512, 0, 512, 768);
        numberLine.setOnAction(event -> {
            if (numberLine.getText().equals("Undraw Number Line")) {
                numberLine.setText("Draw Number Line");
                root.getChildren().remove(xAxis);
                root.getChildren().remove(yAxis);
                view.drawMap();

            } else {
                numberLine.setText("Undraw Number Line");
                xAxis.setStroke(Color.WHITE);
                root.getChildren().add(xAxis);
                yAxis.setStroke(Color.WHITE);
                root.getChildren().add(yAxis);
            }
        });
        Button fileChooser1 = new Button("Operation with data");
        buttonsLayout.getChildren().add(fileChooser1);
        fileChooser1.setOnAction(event -> {
            VBox vbox54 = new VBox(10);
            FileChooser fileChooser = new FileChooser();
            vbox54.setAlignment(Pos.CENTER);
            Scene scene87 = new Scene(vbox54, 300, 300);
            stage.setScene(scene87);
            Button addButton = new Button("Get data from file");
            vbox54.getChildren().add(addButton);
            addButton.setOnAction(event1 -> {
                fileChooser.setTitle("Choose file");
                FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("Text files (*.json)", "*.json");
                fileChooser.getExtensionFilters().add(extFilter);
                File selectedFile = fileChooser.showOpenDialog(stage);
                if (selectedFile != null) {
                    StarMapController newControler = new StarMapController(selectedFile.getAbsolutePath());
                    controller.setConstellations(newControler.getConstellations());
                    controller.setStars(newControler.getStars());
                    view.drawMap();
                }
                stage.setScene(sceneButtons);
            });
            Button saveButton = new Button("Save data to file");
            vbox54.getChildren().add(saveButton);
            saveButton.setOnAction(event1 -> {
                fileChooser.setTitle("Save to file");
                File selectedFile = fileChooser.showSaveDialog(stage);
                FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("Text files (*.json)", "*.json");
                fileChooser.getExtensionFilters().add(extFilter);
                DataWriter.writeFile(selectedFile.getAbsolutePath(), controller);
                stage.setScene(sceneButtons);
            });
        });
        Button reset = new Button("Reset");
        buttonsLayout.getChildren().add(reset);
        reset.setOnAction(event1 -> {
            StarMapController defaultController = new StarMapController("src/main/resources/stars.json");
            controller.setStars(defaultController.getStars());
            controller.setConstellations(defaultController.getConstellations());
            view.drawMap();
            stage.setScene(sceneButtons);
        });
        starModify.setOnAction(event -> {
            VBox layout12 = new VBox(10);
            Scene scene11 = new Scene(layout12, 700, 700);
            Label label = new Label("Choose which star would you like to modify: ");
            layout12.getChildren().add(label);
            List<Button> buttons1 = new ArrayList<>();
            List<Star> stars = new ArrayList<>(controller.getStars());
            for (Star star : stars) {
                String nameOfStar = star.getName();
                Button button = new Button(nameOfStar);
                buttons1.add(button);
                button.setOnAction(event1 -> {
                    VBox options10 = new VBox(10);
                    HBox options11 = new HBox(10);
                    options10.setAlignment(Pos.CENTER);
                    options11.setAlignment(Pos.CENTER);
                    Label label1 = new Label("Change name of the Star");
                    Button changeNameOfStar = new Button("Press, here");
                    changeNameOfStar.setOnAction(event2 -> {
                        VBox addingStar = new VBox(10);
                        Scene scene21 = new Scene(addingStar, 400, 400);
                        stage.setScene(scene21);
                        HBox addingOption1 = new HBox(10);
                        addingOption1.setAlignment(Pos.CENTER);
                        Label starNameLabel = new Label("Write name of star that you want to change to");
                        TextField starName = new TextField();
                        addingOption1.getChildren().addAll(starNameLabel, starName);
                        addingStar.getChildren().add(addingOption1);
                        Button send = new Button("Change name of the star");
                        HBox addingOption4 = new HBox(10);
                        addingOption4.getChildren().add(send);
                        addingOption4.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption4);
                        send.setOnAction(event3 -> {
                            String name = starName.getText();
                            Optional<Star> star12 = controller.getStarByName(nameOfStar);
                            Star star13 = star12.get();
                            star13.setName(name);
                            view.drawMap();
                            stage.setScene(sceneButtons);
                        });
                    });
                    options11.getChildren().addAll(label1, changeNameOfStar);
                    options10.getChildren().add(options11);
                    Label label2 = new Label("Position of the Star");
                    Button changePositionOfStar = new Button("Press, here");
                    changePositionOfStar.setOnAction(event2 -> {
                        VBox addingStar = new VBox(10);
                        Scene scene21 = new Scene(addingStar, 500, 500);
                        stage.setScene(scene21);
                        HBox addingOption16 = new HBox(10);
                        addingStar.getChildren().add(addingOption16);
                        Label label33 = new Label("Position X");
                        addingOption16.setAlignment(Pos.CENTER);
                        Slider slider = new Slider(0, 1024, 512);
                        slider.setShowTickMarks(true);
                        slider.setShowTickLabels(true);
                        slider.setMajorTickUnit(10);
                        slider.setMinorTickCount(3);
                        slider.setBlockIncrement(5);
                        slider.setSnapToTicks(true);
                        Label label44 = new Label("...");
                        slider.valueProperty().addListener((observable, oldValue, newValue) -> label44.setText(Integer.toString((int) slider.getValue())));
                        addingOption16.getChildren().addAll(label33, label44, slider);
                        HBox addingOption23 = new HBox(10);
                        addingOption23.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption23);
                        Label label77 = new Label("Position Y");
                        Slider slider1 = new Slider(0, 768, 384);
                        slider1.setShowTickMarks(true);
                        slider1.setShowTickLabels(true);
                        slider1.setMajorTickUnit(10);
                        slider1.setMinorTickCount(3);
                        slider1.setBlockIncrement(5);
                        slider1.setSnapToTicks(true);
                        Label label66 = new Label("...");
                        slider1.valueProperty().addListener((observable, oldValue, newValue) -> label66.setText(Integer.toString((int) slider1.getValue())));
                        addingOption23.getChildren().addAll(label77, label66, slider1);
                        Button send = new Button("Change position");
                        HBox addingOption41 = new HBox(10);
                        addingOption41.getChildren().add(send);
                        addingOption41.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption41);
                        send.setOnAction(event3 -> {
                            Optional<Star> star12 = controller.getStarByName(nameOfStar);
                            Star star13 = star12.get();
                            double valueX = slider.getValue();
                            double valueY = slider1.getValue();
                            star13.setxPosition(valueX);
                            star13.setyPosition(valueY);
                            view.drawMap();
                            stage.setScene(sceneButtons);
                            stage.show();
                        });
                    });
                    HBox options12 = new HBox(10);
                    options12.setAlignment(Pos.CENTER);
                    options12.getChildren().addAll(label2, changePositionOfStar);
                    options10.getChildren().add(options12);
                    HBox options13 = new HBox(10);
                    options13.setAlignment(Pos.CENTER);
                    Label label3 = new Label("Brightness of the Star");
                    Button changeBrightnessOfStar = new Button("Press, here");
                    changeBrightnessOfStar.setOnAction(event2 -> {
                        VBox addingStar = new VBox(10);
                        Scene scene21 = new Scene(addingStar, 500, 500);
                        stage.setScene(scene21);
                        HBox addingOption23 = new HBox(10);
                        addingOption23.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption23);
                        Label label77 = new Label("Brightness");
                        Slider slider1 = new Slider(0, 1, 0.5);
                        slider1.setShowTickMarks(true);
                        slider1.setShowTickLabels(true);
                        Label label66 = new Label("...");
                        slider1.valueProperty().addListener((observable, oldValue, newValue) -> label66.setText(Double.toString(slider1.getValue())));
                        addingOption23.getChildren().addAll(label77, label66, slider1);
                        Button send = new Button("Change brigthness");
                        HBox addingOption41 = new HBox(10);
                        addingOption41.getChildren().add(send);
                        addingOption41.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption41);
                        send.setOnAction(event3 -> {
                            Optional<Star> star12 = controller.getStarByName(nameOfStar);
                            Star star13 = star12.get();
                            double valueB = slider1.getValue();
                            star13.setBrightness(valueB);
                            view.drawMap();
                            stage.setScene(sceneButtons);
                            stage.show();
                        });
                    });
                    options13.getChildren().addAll(label3, changeBrightnessOfStar);
                    options10.getChildren().add(options13);
                    Scene scene1 = new Scene(options10, 400, 400);
                    stage.setScene(scene1);
                    stage.show();
                });
            }
            for (Button button6 : buttons1) {
                layout12.getChildren().add(button6);
            }
            layout12.setAlignment(Pos.CENTER);
            stage.setScene(scene11);
            stage.show();
        });
        constelationModify.setOnAction(event6 -> {
            VBox layout3 = new VBox(10);
            Scene scene = new Scene(layout3, 300, 300);
            stage.setScene(scene);
            Label label7 = new Label("Choose which constelation would you like to modify: ");
            List<Button> buttons5 = new ArrayList<>();
            List<Constellation> constellations = new ArrayList<>(controller.getConstellations());
            for (Constellation constellation : constellations) {
                String nameOfConstelation = constellation.getName();
                Button button = new Button(nameOfConstelation);
                button.setOnAction((event1) -> {
                    VBox options = new VBox(10);
                    HBox options1 = new HBox(10);
                    options1.setAlignment(Pos.CENTER);
                    Label label1 = new Label("Add Star");
                    Button addStar = new Button("Press, here");
                    addStar.setOnAction(event2 -> {
                        VBox addingStar = new VBox(10);
                        HBox addingOption1 = new HBox(10);
                        addingOption1.setAlignment(Pos.CENTER);
                        Label starNameLabel = new Label("Write name of star that you want to add");
                        TextField starName = new TextField();
                        addingOption1.getChildren().addAll(starNameLabel, starName);
                        addingStar.getChildren().add(addingOption1);
                        HBox addingOption2 = new HBox(10);
                        addingOption2.setAlignment(Pos.CENTER);
                        Label starPos = new Label("Add position of the star");
                        Label x1 = new Label("X: ");
                        TextField starPosX = new TextField();
                        Label y1 = new Label("Y: ");
                        TextField starPosY = new TextField();
                        addingOption2.getChildren().addAll(starPos, x1, starPosX, y1, starPosY);
                        addingStar.getChildren().add(addingOption2);
                        HBox addingOption3 = new HBox(10);
                        addingOption3.setAlignment(Pos.CENTER);
                        Label starBrightness = new Label("Add star brightness");
                        TextField starBritness = new TextField();
                        addingOption3.getChildren().addAll(starBrightness, starBritness);
                        addingStar.getChildren().add(addingOption3);
                        Button send = new Button("Add star");
                        HBox addingOption4 = new HBox(10);
                        addingOption4.getChildren().add(send);
                        addingOption4.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption4);
                        send.setOnAction(event3 -> {
                            String name = starName.getText();
                            int x = Integer.parseInt(starPosX.getText());
                            int y = Integer.parseInt(starPosY.getText());
                            double b = Double.parseDouble(starBritness.getText());
                            Star star = new Star(name, x, y, b);
                            constellation.addStar(star);
                            controller.addStar(star);
                            view.drawMap();
                            view.drawConstellations();
                            stage.setScene(sceneButtons);
                        });
                        Scene scene1 = new Scene(addingStar, 400, 400);
                        stage.setScene(scene1);
                        stage.show();
                    });
                    options1.getChildren().addAll(label1, addStar);
                    options.getChildren().add(options1);
                    HBox options2 = new HBox(10);
                    options2.setAlignment(Pos.CENTER);
                    Label label2 = new Label("Remove Star");
                    Button removeStar = new Button("Press, here");
                    removeStar.setOnAction(event2 -> {
                        VBox addingStar = new VBox(10);
                        HBox addingOption1 = new HBox(10);
                        addingOption1.setAlignment(Pos.CENTER);
                        Label starNameLabel = new Label("Write name of star that you want to remove");
                        TextField starName = new TextField();
                        addingOption1.getChildren().addAll(starNameLabel, starName);
                        addingStar.getChildren().add(addingOption1);
                        Button send = new Button("Remove star");
                        HBox addingOption4 = new HBox(10);
                        addingOption4.getChildren().add(send);
                        addingOption4.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption4);
                        send.setOnAction(event3 -> {
                            String name = starName.getText();
                            constellation.removeStar(name);
                            controller.removeStar(name);
                            view.drawConstellations();
                            view.drawMap();
                            stage.setScene(sceneButtons);
                        });
                        Scene scene1 = new Scene(addingStar, 400, 400);
                        stage.setScene(scene1);
                        stage.show();
                    });
                    options2.getChildren().addAll(label2, removeStar);
                    options.getChildren().add(options2);
                    HBox options3 = new HBox(10);
                    options3.setAlignment(Pos.CENTER);
                    Label label3 = new Label("Move Star");
                    Button moveStar = new Button("Press, here");
                    moveStar.setOnAction(event2 -> {
                        VBox addingStar = new VBox(10);
                        HBox addingOption1 = new HBox(10);
                        addingOption1.setAlignment(Pos.CENTER);
                        Label starNameLabel = new Label("Write name of star that you want to move");
                        TextField starName = new TextField();
                        addingOption1.getChildren().addAll(starNameLabel, starName);
                        addingStar.getChildren().add(addingOption1);
                        Label labelMove = new Label("Choose to which constelation would you like to move star: ");
                        List<Constellation> constellations1 = new ArrayList<>(controller.getConstellations());
                        ChoiceBox<String> constellationChoiceBox = new ChoiceBox<>();
                        for (Constellation constellation3 : constellations1) {
                            constellationChoiceBox.getItems().add(constellation3.getName());
                        }
                        HBox addingOption2 = new HBox(10);
                        addingOption2.getChildren().addAll(labelMove, constellationChoiceBox);
                        addingStar.getChildren().add(addingOption2);
                        Button send = new Button("Move star");
                        HBox addingOption4 = new HBox(10);
                        addingOption4.getChildren().add(send);
                        addingOption4.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption4);
                        send.setOnAction(event3 -> {
                            String name = starName.getText();
                            Optional<Constellation> constelation2 = controller.getConstellationByName(constellationChoiceBox.getValue());
                            Constellation constellation3 = constelation2.get();
                            Optional<Star> star = controller.getStarByName(name);
                            constellation3.addStar(star.get());
                            constellation.removeStar(name);
                            view.drawMap();
                            view.drawConstellations();
                            stage.setScene(sceneButtons);
                        });
                        Scene scene1 = new Scene(addingStar, 400, 400);
                        stage.setScene(scene1);
                        stage.show();
                    });
                    options3.getChildren().addAll(label3, moveStar);
                    options.getChildren().add(options3);
                    HBox options4 = new HBox(10);
                    options4.setAlignment(Pos.CENTER);
                    Label label4 = new Label("Change Name Of the Constelation");
                    Button changeNameOfStar = new Button("Press, here");
                    changeNameOfStar.setOnAction(event2 -> {
                        VBox addingStar = new VBox(10);
                        HBox addingOption1 = new HBox(10);
                        addingOption1.setAlignment(Pos.CENTER);
                        Label starNameLabel = new Label("Write name of Constelation that you want to change name of");
                        TextField starName = new TextField();
                        addingOption1.getChildren().addAll(starNameLabel, starName);
                        addingStar.getChildren().add(addingOption1);
                        Button send = new Button("Change name of the Constelation");
                        HBox addingOption4 = new HBox(10);
                        addingOption4.getChildren().add(send);
                        addingOption4.setAlignment(Pos.CENTER);
                        addingStar.getChildren().add(addingOption4);
                        send.setOnAction(event3 -> {
                            String name = starName.getText();
                            constellation.setName(name);
                            view.drawMap();
                            view.drawConstellations();
                            stage.setScene(sceneButtons);
                        });
                        Scene scene1 = new Scene(addingStar, 400, 400);
                        stage.setScene(scene1);
                        stage.show();
                    });
                    options4.getChildren().addAll(label4, changeNameOfStar);
                    options.getChildren().add(options4);
                    options.setAlignment(Pos.CENTER_RIGHT);
                    Scene scene1 = new Scene(options, 300, 300);
                    stage.setScene(scene1);
                    stage.show();
                });
                buttons5.add(button);
            }
            layout3.getChildren().add(label7);
            for (Button button : buttons5) {
                layout3.getChildren().add(button);
            }
            layout3.setAlignment(Pos.CENTER);
            stage.show();
        });
        stage.setScene(sceneButtons);
        stage.show();
        primaryStage.setTitle("Star Map");
        primaryStage.setScene(scene2);
        primaryStage.show();
        view.drawMap(); // Call this after the scene is shown
    }
}