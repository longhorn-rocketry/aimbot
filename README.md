# Aimbot

An experimental control algorithm for seeking apogees with fast-burning, airbrake-equipped rockets. R&D is ongoing at the University of Texas at Austin for application in Spaceport America Cup rockets in the 10k foot category.

### Library

This repository follows the Arduino IDE 1.5 library specification and so is easily installed in this environment.

### Legacy Implementation

The first prototype of the algorithm can be found in `legacy`. This implementation uses a static drag coefficient in its drag force calculations and does not consider the effect of airbrake deployment on body airflow. Despite the shortcomings of the aerodynamics, when applied in simulation, the prototype confirmed our theory that accurate apogee control can be achieved even with significant noise in extrapolated altitude bounds.
