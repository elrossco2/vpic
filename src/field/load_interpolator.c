#include <field_pipelines.h>

void
load_interpolator( interpolator_t * ALIGNED fi,
                   const field_t * ALIGNED f,
                   const grid_t * g ) {
  load_interpolator_pipeline_args_t args[1];
  pipeline_request_t request[1];

  if( fi==NULL ) { ERROR(("Bad interpolator")); return; }
  if( f==NULL )  { ERROR(("Bad field"));        return; }
  if( g==NULL )  { ERROR(("Bad grid"));         return; }

  args->fi = fi;
  args->f  = f;
  args->g  = g;  
  dispatch_pipelines( load_interpolator_pipeline, args, 0, request );  
  wait_for_pipelines( request );
}
