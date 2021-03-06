{
    //- terminal display
    Info << "C mass balance (kg/s) : sourceTerm = " << fvc::domainIntegrate(sourceTerm).value() << " ; ";
    forAll(phi.boundaryField(),patchi)
    {
        if (mesh.boundaryMesh()[patchi].type() == "patch")
        {
            Info << phi.boundaryField()[patchi].patch().name() << " = " <<  -sum(phi.boundaryField()[patchi]*C.boundaryField()[patchi]) << " ; ";
        }
    }
    Info << endl;

    //- CSV output
    if (CSVactive)
    {
        massBalanceCSV << runTime.timeName() << " " << fvc::domainIntegrate(hwater*C*eps).value();
        forAll(mesh.boundaryMesh(),patchi)
        {
            if (mesh.boundaryMesh()[patchi].type() == "patch")
            {
                massBalanceCSV << " " << -sum(phi.boundaryField()[patchi]*C.boundaryField()[patchi]);
            }
        }
        massBalanceCSV << endl;       
    }
}
