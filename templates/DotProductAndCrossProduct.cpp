double dotProduct(const vector<double>& vec1,const vector<double>& vec2)
{
    double result = 0;
    for (int i = 0; i < 3; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

// Function to calculate the cross product of two vectors
//A × B = (bz – cy)i – (az – cx)j + (ay – bx)k = (bz – cy)i + (cx – az)j + (ay – bx)k
//A={a,b,c}
//B={x,y,z}
vector<double> crossProduct(const vector<double>& vec1,const vector<double>& vec2)
{
    vector<double> result(3, 0);
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
    return result;
}