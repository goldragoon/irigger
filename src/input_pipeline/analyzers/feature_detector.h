#ifndef FACERIG_FEATURES_DETECTOR_H
#define FACERIG_FEATURES_DETECTOR_H

#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <array>
#include <vector>

#include "../camera_resolution.h"


class FeatureDetector {
public:
    explicit FeatureDetector(const CamResolution& camera_resolution = CamResolution(640, 480));

    cv::Mat calculate_camera_matrix(CamResolution camera_resolution);
    std::array<float,3> detect_face_direction(const std::array<cv::Point, 68> &landmarks);

private:
    std::array<cv::Point2d, 6> extract_landmark_points(const std::array<cv::Point, 68> &landmarks);

    cv::Mat camera_matrix;
    cv::Mat dist_coeffs;
    std::array<cv::Point3d, 6> reference_points;
};


#endif //FACERIG_FEATURES_DETECTOR_H
