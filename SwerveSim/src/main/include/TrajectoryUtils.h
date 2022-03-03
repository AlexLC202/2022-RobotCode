#include <frc/trajectory/Trajectory.h>
#include <frc/geometry/Pose2d.h>
#include <frc2/command/SwerveControllerCommand.h>
#include "SwerveDrive.h"
#include <vector>

class TrajectoryUtils {
    //the read trajectory thing is never used so I'll leave that out for now
    public:
        frc2::SwerveControllerCommand<4> generateSwerveCommand(SwerveDrive swerveDrive, frc::Trajectory traj);
        frc2::SwerveControllerCommand<4> generateSwerveCommand(SwerveDrive swerveDrive, frc::Trajectory traj, std::function<frc::Rotation2d()> robotHeading);

    private:

};