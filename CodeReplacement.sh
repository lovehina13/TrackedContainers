PROJECT=${1}
for container in vector deque list set map stack queue
do
    inHeader="#include <${container}>"
    inType="std::${container}"
    outFirst=${container:0:1}
    outHeader="#include <TrackedContainers.h>"
    outType="Tracked${outFirst^^}${container:1}"
    grep -lr "${inHeader}" ${PROJECT} | xargs sed -i "s@${inHeader}@${outHeader}@g"
    grep -lr "${inType}" ${PROJECT} | xargs sed -i "s@${inType}@${outType}@g"
done
