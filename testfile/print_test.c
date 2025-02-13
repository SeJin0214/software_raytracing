void	print_world(t_world world);
void	print_plane(void *arg);
void	print_sphere(void *arg);
void	print_cylinder(void *arg);

void	print_world(t_world world)
{
	printf("---------------------ambient_light------------------\n");
	printf("color->%d, %d, %d|\n", world.ambient_light.colors.x, world.ambient_light.colors.y, world.ambient_light.colors.z);
	printf("ratio_in_range->%f|\n", world.ambient_light.ratio_in_range);
	printf("\n\n\n");

	printf("---------------------camera------------------\n");
	printf("cordinate_x->%f\n", world.camera.coordinates.x);
	printf("cordinate_y->%f\n", world.camera.coordinates.y);
	printf("cordinate_z->%f\n", world.camera.coordinates.z);
	printf("field_of_view->%d\n", world.camera.field_of_view);
	printf("normalized_orientation_vector_of_axis_x->%f\n", world.camera.normalized_orientation_vector_of_axis.x);
	printf("normalized_orientation_vector_of_axis_y->%f\n", world.camera.normalized_orientation_vector_of_axis.y);
	printf("normalized_orientation_vector_of_axis_z->%f\n", world.camera.normalized_orientation_vector_of_axis.z);
	printf("\n\n\n");

	printf("---------------------light------------------\n");
	printf("color->%d, %d, %d|\n", world.light.colors.x, world.light.colors.y, world.light.colors.z);
	printf("cordinate_x->%f\n", world.light.coordinates.x);
	printf("cordinate_y->%f\n", world.light.coordinates.y);
	printf("cordinate_z->%f\n", world.light.coordinates.z);
	printf("ratio_in_range->%f|\n", world.light.ratio_in_range);
	printf("\n\n\n");

	printf("---------------------plane------------------\n");
	world.planes.foreach(&world.planes, print_plane);
	printf("\n\n\n");

	printf("---------------------sphere------------------\n");
	world.spheres.foreach(&world.spheres, print_sphere);
	printf("\n\n\n");

	printf("---------------------cylinder------------------\n");
	world.cylinders.foreach(&world.cylinders, print_cylinder);
	printf("\n\n\n");
}

void	print_plane(void *arg)
{
	t_plane	*plane = arg;

	printf("color->%d, %d, %d|\n", plane->colors.x, plane->colors.y, plane->colors.z);
	printf("cordinate_x->%f\n", plane->coordinates.x);
	printf("cordinate_y->%f\n", plane->coordinates.y);
	printf("cordinate_z->%f\n", plane->coordinates.z);
	printf("normalized_orientation_vector_of_axis_x->%f\n", plane->normalized_orientation_vector_of_axis.x);
	printf("normalized_orientation_vector_of_axis_y->%f\n", plane->normalized_orientation_vector_of_axis.y);
	printf("normalized_orientation_vector_of_axis_z->%f\n", plane->normalized_orientation_vector_of_axis.z);
	printf("\n\n");
}

void	print_sphere(void *arg)
{
	t_sphere	*sphere = arg;

	printf("color->%d, %d, %d|\n", sphere->colors.x, sphere->colors.y, sphere->colors.z);
	printf("center-> x = %f, y = %f, z = %f\n", sphere->center.x, sphere->center.y, sphere->center.z);
	printf("diameter->%f\n", sphere->diameter);
	printf("\n\n");
}

void	print_cylinder(void *arg)
{
	t_cylinder	*cylinder = arg;

	printf("color->%d, %d, %d|\n", cylinder->colors.x, cylinder->colors.y, cylinder->colors.z);
	printf("cordinate_x->%f\n", cylinder->coordinates.x);
	printf("cordinate_y->%f\n", cylinder->coordinates.y);
	printf("cordinate_z->%f\n", cylinder->coordinates.z);
	printf("diameter->%f\n", cylinder->diameter);
	printf("height->%f|\n", cylinder->height);
	printf("normalized_orientation_vector_of_axis_x->%f\n", cylinder->normalized_orientation_vector_of_axis.x);
	printf("normalized_orientation_vector_of_axis_y->%f\n", cylinder->normalized_orientation_vector_of_axis.y);
	printf("normalized_orientation_vector_of_axis_z->%f\n", cylinder->normalized_orientation_vector_of_axis.z);
	printf("\n\n");
}
