#!/bin/sh

gpsbabel -i unicsv,utc=5 -f "$1.points" \
	-o gpx -F "$1.gpx" \
	-o gtrnctr,sport=Running,course=0 -x transform,trk=wpt -F "$1.tcx" \
	-o kml,lines=1,points=0,track=1,trackdirection=1 -F "$1.kml"
