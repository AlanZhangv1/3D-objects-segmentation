/**
  @author Vlad-Adrian Moglan
  */

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "cloud_manip.h"
#include "../include/aux_op.h"
#include "../include/image_greyscale.h"
#include "../include/image_rgb.h"
#include "../include/image_mixed.h"
#include "../include/point_xy_greyscale.h"
#include "../include/point_xy_rgb.h"
#include "../include/point_xy_mixed.h"
#include "../include/invalid_cloud_pointer.h"

#include <vector>
#include <stdint.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace cos_lib
{
    namespace img_proc
    {
        /** @return all the x coordinates in the parameter greyscale vector */
        std::vector<float> greyscale_vector_x_coords(
                std::vector<cos_lib::point_xy_greyscale> greyscale_vector);

        /** @return all the y coordinates in the parameter greyscale vector */
        std::vector<float> greyscale_vector_y_coords(
                std::vector<cos_lib::point_xy_greyscale> greyscale_vector);

        /** @return all of the x coordinates in the parameter rgb vector */
        std::vector<float> rgb_vector_x_coords(
                std::vector<cos_lib::point_xy_rgb> rgb_vector);

        /** @return all of the y coordinates in the parameter rgb vector */
        std::vector<float> rgb_vector_y_coords(
                std::vector<cos_lib::point_xy_rgb> rgb_vector);

        /** @return all the x coordinates in a parameter mixed vector */
        std::vector<float> mixed_vector_x_coords(
                std::vector<cos_lib::point_xy_mixed> mixed_vector);

        /** @return all the y coordinates in a parameter mixed vector */
        std::vector<float> mixed_vector_y_coords(
                std::vector<cos_lib::point_xy_mixed> mixed_vector);

        /** @return all the greyscale values in the image **/
        std::vector<unsigned short> greyscale_image_values(
                cos_lib::image_greyscale gs_img);

        /**
         * @brief mixed_vector_to_image converts a 2D mixed points array into a mixed image
         * @param mixed_vector is the array to be converted
         * @param width is the width of the image
         * @param height is the height of the image
         * @return the resulted mixed image
         */
        image_mixed mixed_vector_to_image(
                std::vector<cos_lib::point_xy_mixed> mixed_vector,
                size_t width, size_t height);

        /**
         * @brief mixed_image_to_rgb turns a mixed image into an rgb image
         * @param mixed_img the mixed image to be turned into rgb
         * @return the rgb image
         */
        image_rgb mixed_image_to_rgb(image_mixed mixed_img);

        /**
         * @brief mixed_image_to_greyscale turns a mixed image into a grey scale image
         * @param mixed_img the mixed image to be turned into grey scale
         * @return the grey scale image
         */
        image_greyscale mixed_image_to_greyscale(image_mixed mixed_img);

        /**
         * @brief cloud_to_depth creates a depth image based on a point cloud
         * @param cloud_ptr is a pointer to our point cloud
         * @param width is the width of the image
         * @param height is the height of the image
         * @return the depth image
         */
        image_greyscale cloud_to_depth_image(
                pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr, size_t width, size_t height);

        /**
         * @brief mixed_image_to_cloud creates a pointer to a point cloud based on a mixed image
         * @param mixed is the image that serves as the base for the creation of the point cloud
         * @param base_cloud_ptr is a pointer to the cloud used to create the image
         * @throw invalid_cloud_pointer if base_cloud_ptr is equal to nullptr
         * @return a pointer to the resulted cloud
         */
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr mixed_image_to_cloud(
                image_mixed mixed_img,
                pcl::PointCloud<pcl::PointXYZRGB>::Ptr base_cloud_ptr);

        /**
         * @brief greyscale_image_to_mat transforms an cos_lib::image_greyscale object into a cv::Mat object
         * @param gs_img is the cos_lib::image_greyscale to be transformed into a Mat
         * @return the grey scale image as a Mat object
         */
        cv::Mat greyscale_image_to_mat(image_greyscale gs_img);

        /**
         * @brief rgb_image_to_mat transforms an cos_lib::image_rgb object into a cv::Mat object
         * @param rgb_img is the cos_lib::image_rgb to be transformed into a Mat
         * @return the rgb image as a Mat object
         */
        cv::Mat rgb_image_to_mat(image_rgb rgb_img);

        /**
         * @brief mat_to_greyscale_image transforms a cv::Mat object into an cos_lib::image_greyscale object
         * @param gs_mat is the Mat to be transformed
         * @return an cos_lib::image_greyscale object
         */
        image_greyscale mat_to_greyscale_image(cv::Mat gs_mat);

        /**
         * @brief mat_to_rgb_image transforms a cv::Mat object into an cos_lib::image_rgb object
         * @param rgb_mat is the Mat to be transformed
         * @return an cos_lib::image_rgb object
         */
        image_rgb mat_to_rgb_image(cv::Mat rgb_mat);

        /**
         * @brief detect_contour is a function that detects contours in a depth image
         * @param gs_img is the image to detect the contours of
         * @return the contours in the depth image
         */
        image_greyscale detect_contours(image_greyscale gs_img, int hist_num_cls);

        /**
         * @brief remove_colors removes the parameter colors from the mixed image
         * @param mixed_img is a reference the image to be modified
         * @param colors is the array of colors to be removed
         */
        void remove_colors(image_mixed &mixed_img, std::vector<uint32_t> colors);

        /**
         * @brief normalize augments the greyscale differences between the pixels of an image
         * @param gs_img_ptr is a pointer to the greyscale image to be normalized
         * @throw std::invalid_argument if gs_img_ptr is equal to nullptr
         */
        void normalize(image_greyscale *gs_img_ptr);
    }
}

#endif // IMAGE_PROCESSING_H
