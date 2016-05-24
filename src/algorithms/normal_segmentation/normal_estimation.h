/**
  * @brief this file contains the algorithm for estimating the normals of a point cloud
  * @author Jean-Jacques Ponciano (algorithm), Vlad-Adrian Moglan (code)
  */

#ifndef NORMAL_ESTIMATION_H
#define NORMAL_ESTIMATION_H

#include "../tools/vector3_operations.h"
#include "../tools/aux.h"

/**
 * @brief normal_estimation is a function that estimates the normal vectors of a point cloud
 * @param cloud_ptr is a pointer to the point cloud to estimates the normal vectors of
 * @param radius defines the range in which the k-d tree of cloud will look for the closest neighbours of a given point of the cloud
 * @param max_neighbs is the maximum number of neighbours the kd-tree search function should return
 */
void normal_estimation(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr, float radius, int max_neighbs);

#endif // NORMAL_ESTIMATION_H