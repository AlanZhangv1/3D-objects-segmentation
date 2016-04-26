/**
  * @brief a library containing functions that allow vector operations as well as auxilliary functions for other calculations
  * @author Vlad-Adrian Moglan
  */

#ifndef GEOM_OP_H
#define GEOM_OP_H

#include "vector3.h"

#include <thread>
#include <future>

#include <pcl/kdtree/impl/kdtree_flann.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

#include <boost/lexical_cast.hpp>

namespace geom
{
    /**
     * namespace "vectors" contains vector related functions
     */
    namespace vectors
    {
        /**
         * @brief create_vect2p creates a vector using two points
         * @param pt1 is the point at the arrow of the vector
         * @param pt2 is the point at the 'root' of the vector
         * @return the vector that has been created using 2 points
         */
        vector3 create_vect2p(pcl::PointXYZRGB pt1, pcl::PointXYZRGB pt2);

        /**
         * @brief cross_product calculates the cross product of two vectors
         * @details the cross product of two vectors only has sense in R^3
         * @param vect1 is the first factor of the product
         * @param vect2 is the second factor of the product
         * @return the vector result of the operation
         */
        vector3 cross_product(vector3 vect1, vector3 vect2);

        /**
         * @brief inverse inverses the coordinates of a vector
         * @param vect is the vector to be inversed
         * @return the inversed vector
         */
        vector3 inverse(vector3 vect);

        /**
         * @brief translate_origin translates a vector into the origin
         * @param x1 is the x coordinate of the point at the root of the vector
         * @param y1 is the y coordinate of the point at the root of the vector
         * @param z1 is the z coordinate of the point at the root of the vector
         * @param x2 is the x coordinate of the point at the arrow of the vector
         * @param y2 is the y coordinate of the point at the arrow of the vector
         * @param z2 is the z coordinate of the point at the arrow of the vector
         * @return the vector as a result of the translation
         */
        vector3 translate_origin(float x1, float y1, float z1, float x2, float y2, float z2);

        /**
         * @brief vect_avg calculates the average of the vectors within an array of vectors
         * @param vectors is the array of the vectors we need the average of
         * @return the vector resulted the average of the vectors found within the parameter
         */
        vector3 vect_avg(std::vector<vector3> vectors);

        /**
         * @brief normalize_normal maps the values of the coordinates of a normal between 0 and 1
         * @param normal is the normal to be mapped
         * @return the mapped (normalized) normal
         */
        vector3 normalize_normal(vector3 normal);

        /**
         * @brief pcl_estim_normals is a function that estimates the normals of the parameter cloud using the standard pcl library
         * @param pt_cl is the point cloud to find the normals of
         */
        void pcl_estim_normals(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pt_cl);
    }

    /**
     * namespace "aux" contains auxilliary functions
     */
    namespace aux
    {
        /**
         * @brief float_avg calculates the average of float numbers
         * @param floats is the array of the floats to be averaged
         * @return the averaged of the floats found within the parameter array
         */
        float float_avg(std::vector<float> floats);

        /**
         * @brief calc_sphcoord calculates the spherical coordinates of the point at the arrow of an origin translated vector
         * @param vect the vector having its root at the origin
         * @return an array of 3 floats corresponding to the 3 spherical coordinates of a point (radius, inclination and azimuth)
         */
        std::vector<float> calc_sphcoord(vectors::vector3 vect);

        /**
         * @brief cmp_angles compares the inclination and azimuth angles (spherical coordinate system) of two points
         * @param coords1 is an array containing the radius, inclination and azimuth of the first point
         * @param coords2 is an array containing the radius, inclination and azimuth of the second point
         * @param eps is a float that defines the degree of precision of the comparison
         * @return true if the angles are equal within the boundries of epsilon
         */
        bool cmp_angles(std::vector<float> coords1, std::vector<float> coords2, float eps);

        /**
         * @brief norm_toPtRGB calculates the r, g and b values of a point in function of the coordinates of a given normal
         * @param pt is a pointer to the point to be colored
         * @param normal is the normal used for the calculation
         */
        void norm_toPtRGB(pcl::PointXYZRGB *pt, geom::vectors::vector3 normal);

        /**
         * @brief abs_vector calculates the absolute values of the coordinates of a vector
         * @param vect is the vector to get the absolute values of
         * @return the resulting, absolute value coordinates vector
         */
        geom::vectors::vector3 abs_vector(geom::vectors::vector3 vect);
    }
}

#endif // GEOM_OP_H