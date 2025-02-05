
Double_t findDeltaRP(const RVecD& truthd0_px, const RVecD& truthd0_py, const RVecD& truthd0_pz, const RVecD& truthd0_P )
{
    Int_t station = 0;
    PxPyPzEVector electron_momenta(truthd0_px[station], truthd0_py[station], truthd0_pz[station], truthd0_P[station]);
    PxPyPzEVector positron_momenta(truthd1_px[station], truthd1_py[station], truthd1_pz[station], truthd1_P[station]);
    Double_t deltaR = ROOT::Math::VectorUtil::DeltaR(electron_momenta, positron_momenta);
    return deltaR;
}

Double_t findDeltaR0(const RVecD& truthd0_x, const RVecD& truthd0_y, const RVecD& truthd1_x, const RVecD& truthd1_y  )
{
    Int_t station = 1;
    Double_t deltaR = sqrt( 
                              pow(truthd0_x[station] - truthd1_x[station], 2) 
                            + pow(truthd0_y[station] - truthd1_y[station], 2) 
                        );
    return deltaR;
}

Double_t findTheta(const RVecD& truthd0_x, const RVecD& truthd0_y, const RVecD& truthd0_z,  const RVecD& truthd1_x, const RVecD& truthd1_y, const RVecD& truthd1_z )
{
    Double_t vertex_z = (truthd0_z[0] + truthd1_z[0]) * 0.5; //Average of the z-positions of the two tracks at vertex
    Double_t deltaR0 = findDeltaR0(truthd0_x, truthd0_y, truthd1_x, truthd1_y);
    Double_t final_z = (truthd0_z[1] + truthd1_z[1]) * 0.5; //Average of the z-positions of the two tracks at the final station
    return atan2(deltaR0, final_z - vertex_z);

}
