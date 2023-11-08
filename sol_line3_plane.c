
int	sol_line3_plane3(t_line3 l_, t_plane3 p_, t_line3 *sol_, double *tval)
{
	double	cos;
	
	cos = fabs(tocos_vec3(l_.dir_, p_.dir_));
	if (cos == 0.0)
		return (0);
	else
	{
		if (tval)
		{
			*tval = dist_dot_plane(l_.pos_, p_) / cos;
			if (sol_)
			{
				sol_->dir_ = regular_vec3(ZERO);
				sol_->pos_ = dot_on_line3(l_, *tval);
			}
		}
		return (1);
	}
}
